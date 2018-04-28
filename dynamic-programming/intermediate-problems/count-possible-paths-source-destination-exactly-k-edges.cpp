#include <iostream>

using namespace std; 

int count_walks(int **adj, int v, int s, int d, int k) {
    if (k == 0)
        return 0;
    if (k == 1 && adj[s][d])
        return 1; 
    if (k <= 0)
        return 0;

    int count = 0; 
    for (int i = 0; i < v; i++) {
        if (adj[s][i] == 1)
            count += count_walks(adj, v, i, d, k-1);
    }

    return count;
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
