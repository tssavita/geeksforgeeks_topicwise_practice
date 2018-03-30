#include <iostream>

using namespace std; 

int count_paths(int **maze, int r, int c) {
    if (maze[0][0] == -1)
        return 0;

    for (int i = 1; i < r; i++) {
        if (maze[i][0] == 0)
            maze[i][0] = 1;
        else 
            break;
    }

    for (int i = 1; i < c; i++) {
        if (maze[0][i] == 0)
            maze[0][i] = 1;
        else 
            break;
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (maze[i][j] == -1)
                continue;
            if (maze[i-1][j] > 0)
                maze[i][j] += maze[i-1][j];
            if (maze[i][j-1] > 0)
                maze[i][j] += maze[i][j-1];
        }
    }

    return (maze[r-1][c-1] > 0) ? maze[r-1][c-1] : 0;
}

int main(int argc, char **argv) {
    int r, c;
    cin>>r>>c;
    
    int **maze = new int*[r];
    for (int i = 0; i < r; i++)
        maze[i] = new int[c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) 
            cin>>maze[i][j];
    }

    cout << count_paths(maze, r, c);
}
