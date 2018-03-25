#include <list>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std; 

class Graph {

    int vertices;
    list<int> *array;
    bool *visited;

    public: 

    Graph() {}
    
    Graph(int vertex_number): vertices(vertex_number) {
        array = new list<int>[vertices];
        visited = new bool[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = false; 
    }

    void addEdge(int src, int dest) {
        array[src].push_back(dest);
        array[dest].push_back(src);
    }

    void breadth_first_traversal(int start) {

        queue<int> q;
        q.push(start);

        while ( !q.empty() ) {
            int node = q.front();
            q.pop();
        
            visited[node] = true;
            cout << node << " ";
        
            list<int>::iterator it = array[node].begin();
        
            for (; it != array[node].end(); it++) 
                if( !visited[*it] )
                    q.push(*it);
        }

    }

    void print() {
        for (int i = 0; i < vertices; i++) {
            cout << i << " - ";
            list<int>::iterator it = array[i].begin();
            for (; it != array[i].end(); it++)
                cout << *it <<" " ;
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

    g->breadth_first_traversal(0);
}
