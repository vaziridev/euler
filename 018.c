//ProjectEuler: Problem 18
//Find the max total from top to bottom of triangle (018-matrix.txt)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
void loadMatrix(int matrix[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);
int matrix[SIZE][SIZE] = {0};

int main(void){
  struct timespec start, stop;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  int row = 1, col = 0, num = 0;

  loadMatrix(matrix);
  printMatrix(matrix);



  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
  printf("Solved in %.3f microseconds\n", elapsed);
  return 0;
}
  /*
    Read file into array like so:
      -Create 2D array
      -Create a row counter, a column counter, and scanned counter
      -Initialize counters
      -Read line by line, using the following method to determine index for storage:
        -[columncounter++][row - col]
	-column counter is reset to 0 before each line is read
	-row counter keeps iterating as lines are scanned, and should start at 1
      -Verify proper storage at this point
      -Once everything is set up, simply count up in binary:
        -allocate an array for holding binary (either char or short, tbd)
	-start the binary number at 000000...00 (as many 0's as there are rows, -1)
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
  fp = fopen("018-matrix.txt", "r");
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
