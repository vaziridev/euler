//ProjectEuler: Problem _
//Description
#include <stdio.h>
#include <time.h>

int main(void){
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    //Solution
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("Solved in %.3f microseconds\n", elapsed);
    return 0;
}
