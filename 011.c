//ProjectEuler: Problem 11
//Find the greatest product of four adjacent numbers in the 20x20 grid
#include <stdio.h>
#include <time.h>

#define ROW 20
#define COLUMN 20

int main(){
    FILE *fp;
    int grid[ROW][COLUMN];
    
    fp = fopen("011-grid.txt", "r");

    for(int row = 0; row < ROW; row++){
	for(int column = 0; column < COLUMN; column++){
	    fscanf(fp, "%2d", &grid[row][column]);
	}
    }
    fclose(fp);
    
    for(int row = 0; row < ROW; row++){
	for(int column = 0; column < COLUMN; column++){
	    printf("%02d ", grid[row][column]);
	}
	printf("\n");
    }

    /* TODO:
     * 4) Do grid arithmetic to find largest product of 4 adjacent
     * 5) Return value
     */
    return 0;
}
