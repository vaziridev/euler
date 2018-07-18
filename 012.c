//ProjectEuler: Problem 12
//Find the value of 1st triangle # with over 500 divisors
#include <stdio.h>
#include <time.h>

typedef enum {false, true} bool;

int main(void){
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    bool found = false;		//sentinel value
    int triangleNum = 1;     	//triangle number
    int triangleCounter = 2; 	//triangle number counter

    int divCounter = 0;		//counter for # of divisors

    /**** NOTE: FIRST NEED TO INVESTIGATE ALTERNATIVE TYPE THAT WILL NOT OVERFLOW ****/
    
    do{
	triangleNum += triangleCounter++;	//increase triangle number
	/*check if triangle number has 500+ divisors
	   1) If even, check all #'s from 1 to sqrt+1
	   2) If odd, check all #'s from 1 to sqrt+1, counting up by 2
	   3) In either of the above checks, each divisor found increases divCounter by 2
	   4) As soon as divCounter hits 500+, found = true*/
    }while(!found);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    //output value of triangleNum
    return 0;
}
