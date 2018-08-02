//ProjectEuler: Problem 14
//Find largest collatz sequence started by # below 1 million
#include <stdio.h>
#include <time.h>

int collatz(long int term);

int main(void){
    int longest, term, chain;
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    longest = term = 0;
    for(long int i = 1; i < 1000000; ++i){
	chain = collatz(i);
	if(chain > longest){
	    longest = chain;
	    term = i;
	}
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("Longest chain starts with %d\n", term);
    printf("Solved in %.3f microseconds\n", elapsed);
    return 0;
}

//Returns # of terms in chain
int collatz(long int term){
    int chain = 1;
    while(term != 1){
	if(term % 2){ term = 3*term + 1; }
	else{ term /= 2; }
	++chain;
    }
    return chain;
}
