#include <iostream>
#include <climits>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int min_key(int vertices, int dist[], bool *included) {
    int min_key = INT_MAX, min_index;
    for (int i = 0; i < vertices; i++) {
        if ( !included[i] && min_key > dist[i]) {
            min_key = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void print(int vertices, int dist[]) {
    for (int i = 0; i < vertices; i++) {
        cout << i << " " << dist[i] << " ";
        cout << endl;
    }
    cout << endl;
}

int shortest_path(int vertices, int adjMatrix[9][9]) {
    int dist[vertices];
    bool *included = new bool[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        included[i] = false;
    }

    dist[0] = 0;

    for (int i = 0; i < vertices; i++) {
        int min_vertex = min_key(vertices, dist, included);
        included[min_vertex] = true;

        for (int j = 0; j < vertices; j++) {
            if ( !included[j] && adjMatrix[min_vertex][j] && dist[min_vertex] != INT_MAX  && ((adjMatrix[min_vertex][j] + dist[min_vertex]) < dist[j]))
                dist[j] = adjMatrix[min_vertex][j] + dist[min_vertex];
        }
    }

    print(vertices, dist);
}

int main(int argc, char ** argv) {
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    shortest_path(9, graph);
}
