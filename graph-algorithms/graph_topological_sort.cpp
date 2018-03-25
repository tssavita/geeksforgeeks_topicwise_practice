#include <list>
#include <stack>
#include <iostream>
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

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void topologicalSortUtil(int i, bool *visited, stack<int> *order) {
        visited[i] = true; 
        list<int>::iterator it = adjList[i].begin();
        for (; it != adjList[i].end(); it++) {
            if ( !visited[*it] )
                topologicalSortUtil(*it, visited, order);
        }
        order->push(i);
    }

    void topologicalSort() {

        stack<int> *order = new stack<int>[vertices];
        
        for (int i = 0; i < vertices; i++) {
            if ( !visited[i] )
                topologicalSortUtil(i, visited, order);
        }

        while ( !order->empty() ) {
            cout << order->top() << " ";
            order->pop();
        }

    }

    void print() {
        for (int i = 0; i < vertices; i++) {
            list<int>::iterator it = adjList[i].begin();
            for (; it != adjList[i].end(); it++)
                cout << *it;
        }
    }
};

int main(int argc, char ** argv) {
    int vertex_number;
    cin>>vertex_number;

    Graph *g = new Graph(vertex_number);

    g->addEdge(5, 2);
    g->addEdge(5, 0);
    g->addEdge(4, 0);
    g->addEdge(4, 1);
    g->addEdge(2, 3);
    g->addEdge(3, 1);

    g->topologicalSort();
}
