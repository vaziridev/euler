//ProjectEuler: Problem 13
//Work out the first 10 digits of the sum of one-hundred 50-digit numbers (from 013-number.txt)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Array{
    int *number;
    int size;
}Array;

int main(void){
    FILE *fp;
    Array array;
    int number[50] = {0};
    int i, j, k, carry, sum;

    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    
    //Read first 50-digit number into array
    fp = fopen("013-number.txt", "r");
    array.number = (int *)malloc(sizeof(int) * 50);
    for(i = 0; i < 50; ++i){
	fscanf(fp, "%1d", array.number+i);
    }
    array.size = 50;
    getc(fp);

    //loop through remaining lines
    for(i = 0; i < 49; ++i){
	//Read line into local array
	printf("Adding:\t");
	for(j = 0; j < 50; ++j){
	    number[j] = getc(fp) - '0';
	    printf("%d", number[j]);
	}
	getc(fp);
	printf("\nto:\t");
	for(j = 0; j < array.size; ++j){
	    printf("%d", array.number[j]);
	}
	printf("\n");
	
	//Add arrays together
	carry = 0;
	for(j = 49, k = array.size - 1; j >= 0; --j, --k){ //This loop adds local array to 50 right-most digits
	    sum = array.number[k] + number[j] + carry;
	    array.number[k] = sum % 10;
	    carry = sum / 10;
	}
	for(j = array.size - 50; j > 0; --j){ //This loop adds the carry from local array to remaining left-most digits
	    sum = array.number[j-1] + carry;
	    carry = sum / 10;
	    if(!carry){ break; }
	}
	//If carry remains, realloc
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
	printf("Result:\t");
	for(j = 0; j < array.size; ++j){
	    printf("%d", array.number[j]);
	}
	printf("\n\n");
    }//end for loop
    fclose(fp);
        
    //Output result
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("Found first 10 digits: ");
    for(i = 0; i < 10; ++i){
	printf("%d", array.number[i]);
    }
    printf("\nSolved in %.3f microseconds\n", elapsed);

    //Free memory and return
    free(array.number);
    return 0;
}
