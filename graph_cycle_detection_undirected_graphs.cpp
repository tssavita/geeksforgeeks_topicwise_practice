#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class Graph {
    int vertices;
    list<int> *adjList;
    bool *visited;
    bool *currentRecurseVisit;

    public:

    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
        adjList = new list<int>[vertices];
        visited = new bool[vertices];
        currentRecurseVisit = new bool[vertices];
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    bool cycleDetectionUtil(int i, bool *visited, bool *currentRecurseVisit) {
        if ( !visited[i] ) {
            visited[i] = true;
            currentRecurseVisit[i] = true;

            list<int>::iterator it = adjList[i].begin();
            for (; it != adjList[i].end(); it++) {
                if ( currentRecurseVisit[*it] )
                    return true;
                else if ( !visited[*it] )
                    return cycleDetectionUtil(*it, visited, currentRecurseVisit);
            }

        }

        currentRecurseVisit[i] = false;

        return false;
    }

    bool cycleDetection() {
        for (int i = 0; i < vertices; i++) {
            if ( !visited[i] && cycleDetectionUtil(i, visited, currentRecurseVisit) )
                return true;
        }

        return false;
    }

    void print() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " - ";
            list<int>::iterator it = adjList[i].begin();
            for (; it != adjList[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
    }

};

int main(int argc, char ** argv) {
    
    int vertex_number;
    cin>>vertex_number;

    Graph *g = new Graph(vertex_number);

    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 3);

    g->print();
    cout << "Decision for cycle detection " << g->cycleDetection();
}
