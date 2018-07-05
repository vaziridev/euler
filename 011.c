//ProjectEuler: Problem 11
//Find the greatest product of four adjacent numbers in the 20x20 grid
#include <stdio.h>
#include <time.h>

#define ROW 20
#define COLUMN 20

typedef enum {horizontal, vertical, diagonalR, diagonalL} direction;

int main(){
    FILE *fp;
    int grid[ROW][COLUMN];
    int index[1][2] = {0};
    int product, largest;
    largest = product = 0;
    direction dir;
    struct timespec start, stop;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    //Read grid from file    
    fp = fopen("011-grid.txt", "r");
    for(int row = 0; row < ROW; row++){
	for(int column = 0; column < COLUMN; column++){
	    fscanf(fp, "%2d", &grid[row][column]);
	}
    }
    fclose(fp);

    //Horizontal check
    for(int row = 0; row < ROW; row++){
	for(int column = 0; column < COLUMN - 3; column++){
	    product = grid[row][column];
	    for(int i = 1; i < 4; i++){
		product *= grid[row][column+i];
	    }
	    if(product > largest){
		largest = product;
		index[0][0] = row;
		index[0][1] = column;
		dir = horizontal;
	    }
	}
    }
        
    //Vertical check
    for(int row = 0; row < ROW - 3; row++){
	for(int column = 0; column < COLUMN; column++){
	    product = grid[row][column];
	    for(int i = 1; i < 4; i++){
		product *= grid[row+i][column];
	    }
	    if(product > largest){
		largest = product;
		index[0][0] = row;
		index[0][1] = column;
		dir = vertical;
	    }
	}
    }
        
    //DiagonalR check
    for(int row = 0; row < ROW - 3; row++){
	for(int column = 0; column < COLUMN - 3; column++){
	    product = grid[row][column];
	    for(int i = 1; i < 4; i++){
		product *= grid[row+i][column+i];
	    }
	    if(product > largest){
		largest = product;
		index[0][0] = row;
		index[0][1] = column;
		dir = diagonalR;
	    }
	}
    }

    //DiagonalL check
    for(int row = 0; row < ROW - 3; row++){
	for(int column = 3; column < COLUMN; column++){
	    product = grid[row][column];
	    for(int i = 1; i < 4; i++){
		product *= grid[row+i][column-i];
	    }
	    if(product > largest){
		largest = product;
		index[0][0] = row;
		index[0][1] = column;
		dir = diagonalL;
	    }
	}
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double elapsed = (stop.tv_sec - start.tv_sec) * 1e6 + (stop.tv_nsec - start.tv_nsec) / 1e3;
    printf("Largest product %d found at {%d,%d} in direction %d in: %.3f microseconds\n", largest, index[0][0]+1, index[0][1]+1, dir, elapsed);
    
    return 0;
}
