//ProjectEuler: Problem 13
//Work out the first 10 digits of the sum of one-hundred 50-digit numbers (from 013-number.txt)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *fp;
    int *array;
    int digit;
    
    fp = fopen("013-number.txt", "r");
    array = (int *)malloc(sizeof(int) * 50);
    for(int i = 0; i < 50; ++i){
	fscanf(fp, "%1d", &digit);
	printf("digit #%d = %d\n", i, digit);
    }
    
    printf("%d", sizeof(int));
    
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    //Solution
    //fclose(fp);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("Solved in %.3f microseconds\n", elapsed);
    return 0;
}

/*TODO:
 * Open file (013-number.txt)
 * Allocate memory to hold an array of 50 ints, all set to 0
 * Read first line into newly allocated array
 * Create a local array for holding each line, 50 ints as well
 * Loop until all lines read:
 *   Read next line into local array
 *   Add local array to dynamic array, right to left
 *   If left-most addition goes over 9, reallocate dynamic array
 *   Shift digits over accordingly
 * Close file
 * Check and display result
 */
