#include <iostream>

using namespace std; 

bool is_okay(int x, int y, int n, int **steps) {
    return ((x >= 0) && (x < n) && (y >= 0) && (y < n) && (steps[x][y] == -1));
}

void print(int **steps, int n) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) 
            cout << steps[i][j] << " ";
        cout << endl;
    }
}

bool knights_tour_util(int x, int y, int move, int **steps, int n, int xmoves[], int ymoves[]) {

    if (move == n * n)
        return true;

    for (int i = 0; i < 8; i++) {
        int nextx = x + xmoves[i];
        int nexty = y + ymoves[i];
        if (is_okay(nextx, nexty, n, steps)) {
            steps[nextx][nexty] = move;
            if (knights_tour_util(nextx, nexty, move + 1, steps, n, xmoves, ymoves))
                return true;
            else 
                steps[nextx][nexty] = -1;
        }
    }

    return false; 
}

bool knights_tour(int n) {
    int **steps = new int*[n];
    for (int i = 0; i < n; i++) 
        steps[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            steps[i][j] = -1;
    }
    steps[0][0] = 0;

    int xmoves[] = {1, 2, -1, -2, -1, -2, 1, 2};
    int ymoves[] = {2, 1, 2, 1, -2, -1, -2, -1};

    if ( !knights_tour_util(0, 0, 1, steps, n, xmoves, ymoves) )
        return false;

    print(steps, n);
    return true;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    
    knights_tour(n);
}
