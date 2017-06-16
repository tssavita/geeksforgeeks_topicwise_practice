#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std; 

#include <iostream>

using namespace std; 

#define N 9

bool notassigned(int x) {
    return (x == 0)? true : false;
}

bool usedInRow(int grid[N][N], int row, int digit) {
    for (int i = 0; i < N; i++)
        if (grid[row][i] == digit)
            return true;

    return false;
}

bool usedInColumn(int grid[N][N], int column, int digit) {
    for (int j = 0; j < N; j++) 
        if (grid[j][column] == digit)
            return true;

    return false;
}

bool usedInGrid(int grid[N][N], int row, int column, int digit) {
    /* Rounding up to get the end of grid from cell position*/
    int g_r_start = (row / 3) * 3;
    int g_r_end = (row == 0)? 0 : ((row + 3 - 1) / 3) * 3;
    int g_c_start = (column / 3) * 3;
    int g_c_end = (column == 0)? 0: ((column + 3 - 1) / 3) * 3;
    
    for (int i = g_r_start; i < g_r_end; i++) 
        for (int j = g_c_start; j < g_c_end; j++) 
            if (grid[i][j] == digit) 
                return true; 

    return false; 
}



bool solve(int grid[N][N]) {
    
    int row = -1, column = -1;
    bool flag = false;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                row = i, column = j;
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }

    if (row == -1 && column == -1)
        return true; 

    for (int k = 1; k <= 9; k++) {

        if ( !usedInRow(grid, row, k) && !usedInColumn(grid, column, k) && 
            !usedInGrid(grid, row, column, k) ) {
            grid[row][column] = k; 
        
            if (solve(grid))
                return true;
       
            grid[row][column] = 0;
        }
    }           
    
    return false;
}

int printSolution(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
    }
}

int main() {
    int t;
    cin>>t;
    for (int i = 0; i < t; i++) {
        int grid[N][N];
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin>>grid[j][k];
            }
        }
        if (solve(grid) == true)
            printSolution(grid);
        else {
            printSolution(grid);
            cout << "Not solveable";
        }
        
        cout << endl;
    }
	
	return 0;
}
