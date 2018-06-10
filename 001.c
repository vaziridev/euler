//ProjectEuler: Problem 1
//Find the sum of all the multiples of 3 or 5 below 1000.
#include <stdio.h>
#include <time.h>

#define LIMIT 1000

int findSum(int limit);

int main(void){
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    int sum = findSum(LIMIT);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e6 + (stop.tv_nsec - start.tv_nsec) / 1e3;
    printf("The sum of all multiples of 3 or 5 below %d is: %d\nResult obtained in: %.3f microseconds\n",
	   LIMIT, sum, elapsed);
    return 0;
}

int findSum(int limit){
    int i, sum = 0;
    for(int i = 3; i < limit; i+=3){ sum+=i; }
    for(int i = 5; i < limit; i+=5){ if(i%3) sum+=i; }
    return sum;
}
