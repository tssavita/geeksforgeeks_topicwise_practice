#include <iostream>

using namespace std; 

int count_walks(int **adj, int v, int s, int d, int k) {
    int cache[v][v][k+1];
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {

                cache[i][j][e] = 0;
                if (e == 0 && i == j)
                    cache[i][j][e] = 1;
                if (e == 1 && adj[i][j])
                    cache[i][j][e] = 1;
                if (e > 1) {
                    for (int l = 0; l < v; l++) 
                        if (adj[i][l] == 1)
                            cache[i][j][e] += cache[l][j][e-1];
                }
            }
        }
    }

    return cache[s][d][k];
}

int main(int argc, char ** argv) {
    int s, d, v, k;
    cin>>s>>d>>v>>k;

    int **adj = new int*[v];
    for (int i = 0; i < v; i++) 
        adj[i] = new int[v];

    for (int i = 0; i < v; i++) 
        for (int j = 0; j < v; j++)
            cin>>adj[i][j];

    cout << count_walks(adj, v, s, d, k);
}
