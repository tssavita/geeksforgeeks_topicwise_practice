#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cstddef>
#include <vector>

using namespace std;

int minimumKey(int vertices, int key[], bool mstSet[]) {
    int minKeyValue = INT_MAX;
    int minKeyIndex = -1;
    for (int i = 0; i < vertices; i++) {
        if ( !mstSet[i] && (key[i] < minKeyValue) )
            minKeyValue = key[i];
            minKeyIndex = i;
    }
    return minKeyIndex;
}

void primsMST(int vertices, vector< vector<int> > adjMatrix){
    int key[vertices];
    bool mstSet[vertices];
    int parent[vertices];

    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int v1 = 0; v1 < vertices; v1++) {
        int minKeyVertex = minimumKey(vertices, key, mstSet);
        mstSet[minKeyVertex] = true;
        for (int v2 = 0; v2 < vertices; v2++) {
            if (adjMatrix[minKeyVertex][v2] && !mstSet[v2] && key[v2] > adjMatrix[minKeyVertex][v2])
                parent[v2] = minKeyVertex, key[v2] = adjMatrix[minKeyVertex][v2];
        }
    }

    for (int j = 1; j < vertices; j++) {
        cout << parent[j] << " - " << j << " " << adjMatrix[parent[j]][j] << endl;
    }
}

int main(int argc, char ** argv) {
    int vertex_number;
    cin>>vertex_number;
    int weight;
    vector< vector<int> > adjMatrix;
    for (int i = 0; i < vertex_number; i++) {
        vector<int> temp;
        for (int j = 0; j < vertex_number; j++) {
            cin>>weight;
            temp.push_back(weight);
        }
        adjMatrix.push_back(temp);
    }
    for (int i = 0; i < vertex_number; i++) {
        for (int j = 0; j < vertex_number; j++)
            cout << adjMatrix.at(i).at(j) << " ";
        cout << endl;
    }
    primsMST(vertex_number, adjMatrix);
}

