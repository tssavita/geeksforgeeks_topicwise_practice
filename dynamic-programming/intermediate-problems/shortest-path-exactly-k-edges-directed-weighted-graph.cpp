#include <iostream>
#include <climits>

using namespace std;

int shortest_paths(int **adj, int v, int s, int d, int k) {
    if (k == 0 && s == d)
        return 0;
    if (k == 1 && adj[s][d] != INT_MAX)
        return adj[s][d]; 
    if (k <= 0)
        return 0; 

    int count = INT_MAX;
    for (int i = 0; i < v; i++) {
        if (adj[s][i] != INT_MAX && i != s && i != d) {
            int temp = shortest_paths(adj, v, i ,d, k-1);
            if (temp != INT_MAX) 
                count = min(count, adj[s][i] + temp);
        }
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

    cout << shortest_paths(adj, v, s, d, k);
}
