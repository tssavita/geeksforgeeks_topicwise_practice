#include <iostream>

using namespace std; 

bool notassigned(int x) {
    return (x == 0)? true : false;
}

bool usedInRow(int grid[][], int row, int digit) {
    for (int i = 0; i < N; i++)
        if (grid[row][i] == digit)
            return true;

    return false;
}

bool usedInColumn(int grid[][], int column, int digit) {
    for (int j = 0; j < M; j++) 
        if (grid[j][column] == digit)
            return true;

    return false;
}

bool usedInGrid(int grid[][], int row, int column, int digit) {
    /* Rounding up to get the end of grid from cell position*/
    int g_r_start = (row / 3) * 3;
    int g_r_end = (row + 3 - 1) / 3;
    int g_c_start = (column / 3) * 3;
    int g_c_end = (column + 3 - 1) / 3;
    
    for (int i = g_r_start; i <= g_r_end; i++) 
        for (int j = g_c_start; j <= g_c_end; j++) 
            if (grid[i][j] == digit) 
                return true; 

    return false; 
}

int foundCellNotAssigned (int grid[][]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) 
                return true;
        }
    }
}

bool solve(int grid[][]) {
    
    int row = -1, column = -1;
    for (int i = 0; i <= 9; i++) {
        bool flag = false;
        for (int j = 0; j <= 9; j++) {
            if (grid[i][j] == UNASSIGNED) {
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }

    if (flag == false)
        return true; 

    for (int k = 1; k <= 9; k++) {

        if ( !usedInRow(grid, i, k) && !usedInColumn(grid, j, k) && !usedInGrid(grid, i, j, k)) {

            grid[i][j] = k; 
        
            if (solve(grid))
                return true;
       
            grid[i][j] == 0;
        }
    }           
    
    return false;
}
