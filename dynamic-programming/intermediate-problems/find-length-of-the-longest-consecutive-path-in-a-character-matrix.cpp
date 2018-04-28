#include <iostream>
#include <cstring>

using namespace std; 

#define n 3
int cache[n+1][n+1];

int xmove[] = {1, 1, 1, 0, -1, -1, -1, 0};
int ymove[] = {1, 0, -1, -1, -1, 0, 1, 1};

int max(int a, int b) {
    return a > b ? a : b;
}

int longest_path(char ** arr, int i, int j, char c) {
    if (i < 0 || j < 0 || i >= n || j >= n)
        return 0;
    if (arr[i][j] != (c + 1))
        return 0;
    if (cache[i][j] != -1)
        return cache[i][j];

    int path = 0;
    for (int k = 0; k < 8; k++) 
        path = max(path, 1 + longest_path(arr, i + xmove[k], j + ymove[k], arr[i][j]));

    cache[i][j] = path;
    return path;
}

int longest_path(char ** arr, char c) {
    int path = 0;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == c) {
                for (int k = 0; k < 8; k++) 
                    path = max(path, 1 + longest_path(arr, i + xmove[k], j + ymove[k], c));
            }
        }
    }

    return path;
}

int main(int argc, char ** argv) {
    char **arr = new char*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new char[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>arr[i][j];
    }

    char c;
    cin>>c;

    cout << longest_path(arr, c);
}
