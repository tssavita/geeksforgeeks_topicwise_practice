#include <iostream>

using namespace std;

class Graph {
    public:
        int vertices;
        int **adjmatrix; 

        Graph() {}

        Graph(int v): vertices(v) {
            adjmatrix = new int*[vertices];
            for (int i = 0; i < vertices; i++) 
                adjmatrix[i] = new int[vertices];
        }

        int minCost(int s, int d) {
            if (s == d || ((s+1) == d))
                return adjmatrix[s][d];

            int min = adjmatrix[s][d];
            for (int i = s+1; i < d; i++) {
                int cost = minCost(s, i) + minCost(i, d);
                if (cost < min)
                    min = cost; 
            }

            return min; 
        }
};

int main(int argc, char ** argv) {
    int v; 
    cin>>v;

    Graph *g = new Graph(v); 
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) 
            cin>>g->adjmatrix[i][j];
    }

    int s, d;
    cin>>s>>d;
    cout << g->minCost(0, v-1);
}
