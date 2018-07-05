//ProjectEuler: Problem 5
//Find the smallest number that is evenly divisible by all numbers from 1-20
#include <stdio.h>
#include <time.h>

typedef enum {false, true} bool;

int main(){
    int i = 1;
    int n = 2520; //smallest # evenly divisible by all #'s from 1-10, in example

    bool num = false;

    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    while(!num){
	while(i <= 20){
	    if(n % i != 0){
		break;
	    }
	    ++i;
	}
	if(i == 21){
	    num = true;
	}
	else{
	    ++n;
	    i = 1;
	}
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e6 + (stop.tv_nsec - start.tv_nsec) / 1e3;
    printf("Smallest number evenly divisible by 1-20 is: %d\nResult obtained in: %.3f microseconds\n", n, elapsed);
    return 0;
}
