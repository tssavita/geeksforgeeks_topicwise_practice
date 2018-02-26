#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>

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

    void depth_first_traversal_util(int i, bool *visited) {
        visited[i] = true;
        cout << i << " ";
        list<int>::iterator it = adjList[i].begin();
        for (; it != adjList[i].end(); it++) 
            if ( !visited[*it] )
                depth_first_traversal_util(*it, visited);
    }

    void depth_first_traversal() {
        cout << "Depth first traversal of the graph ";
        for (int i = 0; i < vertices; i++) {
            if ( !visited[i] )
                depth_first_traversal_util(i, visited);
        }    
    }

    void print() {
        cout << "Adjacency lists of graph vertices ";
        for (int i = 0; i < vertices; i++) {
            list<int>::iterator it = adjList[i].begin();
            cout << i << " - ";
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
    g->addEdge(2, 1);
    g->addEdge(3, 4);
    g->addEdge(2, 4);
    g->addEdge(0, 5);
    g->addEdge(1, 5);
 
    g->print();

    g->depth_first_traversal();    
}
