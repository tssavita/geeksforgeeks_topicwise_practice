#include <iostream>
#include <climits>

using namespace std; 

void floydwarshall(int graph[4][4], int vertices) {
    int shortest_paths[vertices][vertices];
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            shortest_paths[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (shortest_paths[i][k] != INT_MAX && shortest_paths[k][j] != INT_MAX && shortest_paths[i][j] > shortest_paths[i][k] + shortest_paths[k][j])
                    shortest_paths[i][j] = shortest_paths[i][k] + shortest_paths[k][j];
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << shortest_paths[i][j] << "     ";
        }
        cout << endl;
    }
}

int main(int argc, char ** argv) { 
    int graph[4][4] = {{0, 5, INT_MAX, 10}, {INT_MAX, 0, 3, INT_MAX}, {INT_MAX, INT_MAX, 0, 1}, {INT_MAX, INT_MAX, INT_MAX, 0}};
    floydwarshall(graph, 4);
}
