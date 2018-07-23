//ProjectEuler: Problem 13
//Work out the first 10 digits of the sum of one-hundred 50-digit numbers (from 013-number.txt)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//struct
typedef struct Array{
    int *number;
    int size;
}Array;

int main(void){
    FILE *fp;
    //int *array;
    //int size;
    Array array;
    int number[50] = {0};
    int i, j, carry, sum;

    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    
    //Read first 50-digit number into array
    fp = fopen("013-number.txt", "r");
    array.number = (int *)malloc(sizeof(int) * 50);
    for(i = 0; i < 50; ++i){
	fscanf(fp, "%1d", array.number+i);
	printf("%d scanned\n", *(array.number+i));
    }
    array.size = 50;
    getc(fp);

    //loop through remaining lines
    for(i = 0; i < 49; ++i){
	//Read line into local array
	for(j = 0; j < 50; ++j){
	    number[j] = getc(fp) - '0';
	}
	getc(fp);

	//Add arrays together
	carry = 0;
	for(j = array.size - 1; j >= 0; --j){
	    sum = *(array.number+j) + number[j] + carry;
	    *(array.number+j) = sum % 10;
	    carry = sum / 10;
	}//end for loop

	//If carry, realloc
	if(carry){
	    int *temp = realloc(array.number, ++(array.size) * sizeof(int));
	    if(temp == NULL){ printf("Something went wrong during realloc\n"); }
	    else{
		array.number = temp;
		//Shift digits +1 to the right
		for(j = array.size - 1; j > 0; --j){
		    array.number[j] = array.number[j-1];
		}
		array.number[0] = carry;
	    }
	}
	//Debugging: Check resulting array contents
	printf("\nAdded line %d\nResult:\n", i+1);
	for(j = 0; j < array.size; ++j){
	    printf("%d", array.number[j]);
	}
    }//end for loop

    fclose(fp);
    free(array.number);
    
    //Output result
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("\nSolved in %.3f microseconds\n", elapsed);
    return 0;
}

/*TODO:
 * Change array to be within a struct with a size variable
 * Create function to do addition, which takes array and current number
 * Loop until all lines read:
 *   Read next line into local array - done
 *   Add local array to dynamic array, right to left
 *   If left-most addition goes over 9, reallocate dynamic array
 *   Shift digits over accordingly
 * Close file - done
 * Check and display result - sorta done
 * Add error-handling
 */
