#include <stdio.h>
#include <time.h>

#define SIZE 21

int main(){
    //Note: Close to overflow, won't work for larger grids
    unsigned long long int triangle[SIZE][SIZE];
    //Timing variables, start timer
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    //Fill in 1's along top and left border
    for(int i = 0; i < SIZE; ++i){
	triangle[i][0] = 1; //Top row
	triangle[0][i] = 1; //Left column
    }
    //Add previous terms here
    for(int i = 1; i < SIZE; ++i){
	for(int j = 1; j < SIZE; ++j){
	    triangle[i][j] = triangle[i][j-1] + triangle[i-1][j];
	}

    }
    
    //Result output
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e3 + (stop.tv_nsec - start.tv_nsec) / 1e6;
    printf("Found %llu in %.3f microseconds\n", triangle[SIZE-1][SIZE-1], elapsed);
    return 0;
}
