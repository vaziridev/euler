//ProjectEuler: Problem 12
//Find the value of 1st triangle # with over 500 divisors
#include <stdio.h>
#include <math.h>
#include <time.h>
typedef enum {false, true} bool;

int main(void){
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    bool found = false;				//sentinel value
    unsigned long long int triangleNum = 1;    	//triangle number
    unsigned long int triangleCounter = 2;	//triangle number counter

    int divCounter = 0;				//divisor counter

    //Main loop
    do{
	divCounter = 0;				//reset divisor counter
	triangleNum += triangleCounter++;	//increase triangle number
	//Check # of divisors
	if(triangleNum % 2){
	    for(int i = 1; i < (int)ceil(sqrt(triangleNum)); i += 2){
		if(triangleNum % i == 0){ divCounter += 2; }
		if(divCounter >= 500){
		    found = true;
		    break;
		}
	    }
	}
	else{
	    for(int i = 2; i < (int)ceil(sqrt(triangleNum)); i++){
		if(triangleNum % i == 0){ divCounter += 2; }
		if(divCounter >= 500){
		    found = true;
		    break;
		}
	    }
	}
    }while(!found);
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("Found %llu! in %.3f microseconds\n", triangleNum, elapsed);
    return 0;
}
