//ProjectEuler: Problem 3
//Find the largest prime factor of the number 600851475143
#define NUM 600851475143
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef enum {false, true} bool;

bool isPrime(long long int n);
long long int getResult(long long int limit);

int main(void){
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    long long int result = getResult(NUM);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("The largest prime factor of %lli is: %lli\nResult obtained in: %.3f milliseconds\n",
	   NUM, result, elapsed);
    return 0;
}

bool isPrime(long long int n){
    long long int root = sqrt(n) +0.5f;

    if(n==2){ return true; }

    if(n % 2 == 0 || n == 0 || n == 1)
	return false;

    for(int i = 3; i <= root; i = i+2){	if(!(n % i)){ return false; } }

    return true;
}

long long int getResult(long long int limit){
    int i = 2;
    while(limit / i > 1){
	if(!(limit % i)){
	    if(isPrime(limit / i)){
		return limit / i;
	    }
	}
	++i;
    }
    return 0;
}
