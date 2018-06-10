//ProjectEuler: Problem 2
//Find the sum of all even Fibonacci numbers that do not exceed 4 million
#include <stdio.h>
#include <time.h>

#define LIMIT 4000000

long int findSum(int limit);

int main(void){
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    long int sum = findSum(LIMIT);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e6 + (stop.tv_nsec - start.tv_nsec) / 1e3;
    printf("The sum of all even Fibonnaci numbers not exceeding %d is: %li\nResult obtained in: %.3f microseconds\n",
	   LIMIT, sum, elapsed);
    return 0;
}

long int findSum(int limit){
    long int sum = 0;

    for(long int n1=1, n2=2, n3=0; n3<=limit; n3=n1+n2, n1=n2, n2=n3){if(!(n2 % 2)) sum+=n2;}
    return sum;
}
