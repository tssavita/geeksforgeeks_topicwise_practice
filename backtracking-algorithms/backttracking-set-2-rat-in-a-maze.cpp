#include <iostream>

using namespace std;

bool is_okay(int x, int y, int n, int ** maze) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < n) && (maze[x][y] == 1));
}

void print(int ** ways, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << ways[i][j] << " ";
        cout << endl;
    }
}

bool rats_way_util(int x, int y, int n, int ** way, int ** maze, int xmove[], int ymove[]) {
    if (x == n-1 && y == n-1) {
        way[x][y] = 1;
        return true; 
    }

    for (int i = 0; i < 2; i++) {
        int nextx = x + xmove[i];
        int nexty = y + ymove[i];
        if ( is_okay(nextx, nexty, n, maze) ) {
            way[nextx][nexty] = 1;
            if (rats_way_util(nextx, nexty, n, way, maze, xmove, ymove) == true)
                return true;
            else 
                way[nextx][nexty] = 0;
        }
    }
    return false; 
}

bool rats_way(int n, int ** maze) {
    int ** way = new int*[n];
    for (int i = 0; i < n; i++)
        way[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            way[i][j] = 0;
    }

    way[0][0] = 1;

    int xmove[] = {0, 1};
    int ymove[] = {1, 0};

    if ( !rats_way_util(0, 0, n, way, maze, xmove, ymove) )
        return false;

    print(way, n);
    return true; 
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int ** maze = new int*[n];
    for (int i = 0; i < n; i++) {
        maze[i] =  new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin>>maze[i][j];
    }

    rats_way(n, maze);
}
