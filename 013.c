//ProjectEuler: Problem 13
//Work out the first 10 digits of the sum of one-hundred 50-digit numbers (from 013-number.txt)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *fp;
    int *array;
    int number[50] = {0};
    int i, j;
    
    //Read first 50-digit number into array
    fp = fopen("013-number.txt", "r");
    array = (int *)malloc(sizeof(int) * 50);
    for(i = 0; i < 50; ++i){
	fscanf(fp, "%1d", array+i);
	//debug: printf("digit #%d = %d\n", i, *(array+i));
    }
    getc(fp); //skip past newline (\n\r, 2 bytes in UTF-8)
    //debug: printf("position: %d, value is %c\n", ftell(fp), getc(fp));

    //loop through every line in file (100 lines, 1 already read)
    for(i = 0; i < 99; ++i){
	//Read line into local array
	for(j = 0; j < 50; ++j){
	    number[j] = getc(fp) - '0';
	}
	getc(fp); //skip past newline (\n\r, 2 bytes in UTF-8)

	//DO ADDITION AND REALLOC HERE
    }
    fclose(fp);

    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    //Solution
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("Solved in %.3f microseconds\n", elapsed);
    return 0;
}

/*TODO:
 * Open file (013-number.txt) - done
 * Allocate memory to hold an array of 50 ints - done
 * Read first line into newly allocated array - done
 * Create a local array for holding each line, 50 ints as well - done
 * Loop until all lines read:
 *   Read next line into local array - done
 *   Add local array to dynamic array, right to left
 *   If left-most addition goes over 9, reallocate dynamic array
 *   Shift digits over accordingly
 * Close file - done
 * Check and display result - sorta done
 */
