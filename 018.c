//ProjectEuler: Problem 18
//Find the max total from top to bottom of triangle (018-matrix.txt)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define FILENAME "018-matrix.txt"

void loadMatrix(int matrix[SIZE][SIZE]);  //load from file into matrix[][]
void printMatrix(int matrix[SIZE][SIZE]); //print contents of matrix[][]
int totalPaths();                         //returns total # of paths
int checkBit(int num, int bit);           //checks value at bit position

int matrix[SIZE][SIZE] = {0};

int main(void){
  int row, col, num, path, sum, i;
  int paths = 1, champion = 0, championPath = 0;

  //Start timer
  struct timespec start, stop;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  
  //Load matrix, calculate total # of paths
  loadMatrix(matrix);
  printMatrix(matrix);
  paths = totalPaths();

  //Check each possible path
  for(path = 0; path < paths; ++path){
    //Reset sum + counters
    sum = matrix[0][0];
    row = col = 0;

    //Check each bit of path and add node to sum (0 is left node, 1 is right)
    for(i = 0; i < SIZE-1; ++i){
      if(!checkBit(path, SIZE-2-i)){ ++row; }
      else{ ++row; ++col; }
      sum += matrix[row][col];
    }
    
    //Set champion
    if(sum > champion){
      champion = sum;
      championPath = path;
    }
  }
  printf("\nChampion is %d!\nPath #%d\n", champion, championPath); //championPath will be used later for improved output

  //Report time elapsed
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
  printf("Solved in %.3f microseconds\n", elapsed);
  return 0;
}

void loadMatrix(int matrix[SIZE][SIZE]){
  FILE *fp;
  int row, col, num;
  fp = fopen(FILENAME, "r");
  for(row=1; row<=SIZE; ++row){
    for(col=row; col>=1; --col){
      fscanf(fp, "%2d", &num);
      matrix[row-1][row-col] = num;
    }
  }
  fclose(fp);
}

void printMatrix(int matrix[SIZE][SIZE]){
  int row, col, num;
  for(row=1; row<=SIZE; ++row){
    for(col=row; col>=1; --col){
      printf("%.2d ", matrix[row-1][row-col]);
    }
    printf("\n");
  }
}

int totalPaths(){
  int total = 1;
  for(int i = 1; i < SIZE; ++i){
    total *= 2;
  }
  return total;
}

int checkBit(int num, int bit){
  if((1 << bit) & num){ return 1; }
  else{ return 0; }
}
