//ProjectEuler: Problem 1
//Find the sume of all the multiples of 3 or 5 below 1000.
#include <stdio.h>

#define LIMIT 1000

int findSum(int limit);

int main(void){
    printf("The sum of all multiples of 3 or 5 below %d is: %d\n",
	   LIMIT, findSum(LIMIT));
    return 0;
}

int findSum(int limit){
    int i, sum = 0;
    for(int i = 3; i < limit; i+=3){ sum+=i; }
    for(int i = 5; i < limit; i+=5){ if(i%3) sum+=i; }
    return sum;
}
	
