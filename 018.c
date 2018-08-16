//ProjectEuler: Problem 18
//Find the max total from top to bottom of triangle (018-matrix.txt)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define FILENAME "018-matrix.txt"

void loadMatrix(int matrix[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);
int checkBit(int num, int bit);

int matrix[SIZE][SIZE] = {0};

int main(void){
  struct timespec start, stop;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  int row, col, num, path, sum, i;
  int totalPaths = 1, champion = 0, championPath = 0;

  //Load matrix, debug output
  loadMatrix(matrix);
  printMatrix(matrix);

  //Debug output
  for(i = 1; i < SIZE; ++i){
    totalPaths *= 2;
  }
  printf("Total paths for triangle with %d rows is: %d\n\n", SIZE, totalPaths);

  //Iterating through each possible path
  for(path = 0; path < totalPaths; ++path){
    //Reset sum + counters
    sum = matrix[0][0];
    row = col = 0;

    //Check each bit of path (0 is left, 1 is right)
    for(i = 0; i < SIZE-1; ++i){
      //Debug output:
      printf("Bit of path #%d at position %d: %d\n",
            path, SIZE-1-i, checkBit(path, SIZE-2-i));
      if(checkBit(path, SIZE-2-i)){ ++row; }
      else{ ++col; }
      printf("Sum = %d + %d\n", sum, matrix[row][col]);
      sum += matrix[row][col];
    }
    printf("Sum of path #%d is %d\n\n", path, sum);
    
    if(sum > champion){
      champion = sum;
      championPath = path+i;
    }
  }
  printf("\nChampion is %d!\n", champion);
  

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
  printf("Solved in %.3f microseconds\n", elapsed);
  return 0;
}
  /*
    Read file into array like so:
	-before incrementing number, sum the numbers at each step (0 is left, 1 is right)
	-a left equates to going down (up) 1 row but staying at the same column, right vice versa
	-keep track of champion
        -once you've hit 1111...111 and checked that path, you're ready to report result
      -Then, take a break and start considering how this could be implemented with a binary tree,
      and learn how to implement pruning as well.
   */


    


void loadMatrix(int matrix[SIZE][SIZE]){
  FILE *fp;
  int row, col, num;
  fp = fopen(FILENAME, "r");
  for(row=1; row<=SIZE; ++row){
    for(col=1; col<=row; ++col){
      fscanf(fp, "%2d", &num);
      matrix[col-1][row-col] = num;
    }
  }
  fclose(fp);
}

void printMatrix(int matrix[SIZE][SIZE]){
  int row, col, num;
  for(row=1; row<=SIZE; ++row){
    for(col=1; col<=row; ++col){
      printf("%.2d ", matrix[col-1][row-col]);
    }
    printf("\n");
  }
}

int checkBit(int num, int bit){
  if((1 << bit) & num){ return 1; }
  else{ return 0; }
}
