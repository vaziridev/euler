//ProjectEuler: Problem 16
//Find the sum of the digits of the number 2^1000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define POWER 1000

typedef struct Array{
  int *number;
  int size;
}Array;

int main(void){
  Array array;
  int i, j, carry, product, sum = 0;
  //Timer stuff
  struct timespec start, stop;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

  //Set up array
  array.number = (int *)malloc(sizeof(int));
  array.size = 1;
  array.number[0] = 2;

  //Multiply 2^POWER
  for(i = 1; i < POWER; ++i){
    //Multiply array by 2
    carry = 0;
    for(j = array.size; j > 0; --j){
      product = array.number[j-1] * 2 + carry;
      array.number[j-1] = product % 10;
      carry = product / 10;
    }

    //Grow array if multiplication created a carry
    if(carry){
      int *temp = realloc(array.number,
			  ++(array.size) * sizeof(int));
      if(temp == NULL){ printf("Realloc error!\n"); }
      else{//Shift digits +1 to the right and add carry
	array.number = temp;
	for(j = array.size - 1; j > 0; --j){
	  array.number[j] = array.number[j-1];
	}
	array.number[0] = carry;
      }
    }

    //Test output
    printf("Value of 2^%d is: ", i+1);
    for(j = 0; j < array.size; ++j){
      printf("%d", array.number[j]);
    }
    printf("\n");
  }

  //Get sum of digits
  for(i = 0; i < array.size; ++i){
    sum += array.number[i];
  }

  //Output result
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
  printf("Sum of the digits in 2^%d: %d\n", POWER, sum);
  printf("Solved in %.3f microseconds\n", elapsed);

  //Free memory and return
  free(array.number);
  return 0;
}
