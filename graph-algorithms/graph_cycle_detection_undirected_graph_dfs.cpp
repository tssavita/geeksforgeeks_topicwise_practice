#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <climits>

using namespace std;

class Graph {
    int vertices;
    list<int> *adjList;
    bool *visited;

    public: 

    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
        adjList = new list<int>[vertices];
        visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false;
    }

    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }


    bool cycleDetectionUtil(int i, bool *visited, int parent) {
        visited[i] = true;
        list<int>::iterator it = adjList[i].begin();
        for (; it != adjList[i].end(); it++) {
            if ( !visited[*it] ) {
                if (cycleDetectionUtil(*it, visited, i))
                    return true;
            }
            else if ( *it != parent )
                return true;
        }
        return false;
    }

    bool cycleDetection() {
        for (int i = 0; i < vertices; i++)
            if ( !visited[i] && cycleDetectionUtil(i, visited, INT_MIN) )
                return true;

        return false;
    }

};

int main(int argc, char ** argv) {
    int vertex_number;
    cin>>vertex_number;

    Graph *g = new Graph(vertex_number);
    g->addEdge(1, 0);
    g->addEdge(0, 2);
    g->addEdge(2, 0);
    g->addEdge(0, 3);
    g->addEdge(3, 4);

    cout << "Is Graph cyclic? 1(Yes) or 0(No) " << g->cycleDetection() << endl;

    Graph *g1 = new Graph(3);
    g1->addEdge(0, 1);
    g1->addEdge(1, 2);

    cout << "Is Graph cyclic? 1(Yes) or 0(No) " << g1->cycleDetection() << endl;
}
