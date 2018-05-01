#include <iostream>
#include <cstring>

using namespace std; 

class Graph {
    public: 
        int vertices; 
        int **adjmatrix;

        Graph() {}

        Graph(int v, int **mat): vertices(v) {
            adjmatrix = new int*[vertices];
            for (int i = 0; i < vertices; i++) 
                adjmatrix[i] = new int[vertices];
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) 
                    adjmatrix[i][j] = mat[i][j];
            }
        }

        bool isSafe(int i, int j) {
            return (i >= 0 && i < vertices && j >= 0 && j < vertices && adjmatrix[i][j]);
        }

        int DFSUtil(int i, int j, bool **visited) {
            int xmoves[8] = {1, 1, 0, -1, -1, -1, 0, 1};
            int ymoves[8] = {0, 1, 1, 1, 0, -1, -1, -1};
            visited[i][j] = true; 

            for (int k = 0; k < 8; k++) {
                if (isSafe(i + xmoves[k], j + ymoves[k]) && !visited[i][j]) 
                    DFSUtil(i + xmoves[k], j + ymoves[k], visited);
            }
        }

        int countIslands() {

            int count = 0;
            bool **visited;
            visited = new bool*[vertices];
            for (int i = 0; i < vertices; i++)
                visited[i] = new bool[vertices];

            for (int i = 0; i < vertices; i++)
                for (int j = 0; j < vertices; j++)
                    visited[i][j] = false;

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (adjmatrix[i][j] && !visited[i][j]) {
                        DFSUtil(i, j, visited);
                        cout << i << " " << j;
                        count++;
                    }
                }
            }
            return count;
        }
};

int main(int argc, char ** argv) {
    int v;
    cin>>v;

    int **mat;
    mat = new int*[v];
    for (int i = 0; i < v; i++) 
        mat[i] = new int[v];

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++)
            cin>>mat[i][j];
    }

    Graph *g = new Graph(v, mat);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << g->adjmatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << g->countIslands();
}
