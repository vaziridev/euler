//ProjectEuler: Problem 12
//Find the value of 1st triangle # with over 500 divisors
#include <stdio.h>
#include <time.h>

int main(void){
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    //Do things here
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    return 0;
}
