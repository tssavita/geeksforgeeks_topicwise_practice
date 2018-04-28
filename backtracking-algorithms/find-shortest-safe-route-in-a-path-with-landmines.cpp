#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

#define R 12
#define C 10

int xmove[] = {-1, 0, 0, 1};
int ymove[] = {0, -1, 1, 0};

bool min(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}

bool is_safe(int mat[R][C], bool visited[R][C], int x, int y) {
    if (mat[x][y] == 0 || visited[x][y])
        return false;

    return true;
}

bool is_valid(int x, int y) {
    if (x >= 0 && x < R && y >= 0 && y < C)
        return true;

    return false;
}

void mark_unsafe_cells(int mat[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    if (is_valid(i + xmove[k], j + ymove[k]))
                        mat[i + xmove[k]][j + ymove[k]] =   -1; 
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
}

void shortest_path_util(int mat[R][C], bool visited[R][C], int nextx, int nexty, int min_dist, int curr_dist) {

    if (nexty == C - 1) {
        min_dist = min(curr_dist, min_dist);
        return;
    }

    if (curr_dist > min_dist)
        return;

    visited[nextx][nexty] = true; 

    for (int k = 0; k < 4; k++) {
        if (is_valid(nextx + xmove[k], nexty + ymove[k]) && is_safe(mat, visited, nextx + xmove[k], nexty + ymove[k]))
            shortest_path_util(mat, visited, nextx + xmove[k], nexty + ymove[k], min_dist, curr_dist + 1);
    }
    
    visited[nextx][nexty] = false;
}

void shortest_path(int mat[R][C]) {
    int min_dist = INT_MAX; 

    bool visited[R][C];

    mark_unsafe_cells(mat);

    for (int i = 0; i < R; i++) {
        if (mat[i][0] == 1) {
            memset(visited, false, sizeof(visited));
            shortest_path_util(mat, visited, i, 0, min_dist, 0);

            if (min_dist == C - 1)
                break;
        }
    }

    if (min_dist != INT_MAX)
        cout << min_dist;
    else 
        cout << "last column not reachable";
}

int main(int argc, char **argv) {
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    shortest_path(mat);
}
