#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int vertices;
    list<int> *adjList;

    bool *visited;
    vector<int> incomingEdges;

    public:

    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
        adjList = new list<int>[vertices];
        visited = new bool[vertices];
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
            incomingEdges.push_back(0);
        }
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        incomingEdges[dest]++;
    }

    void allTopologicalSortsUtil(bool *visited, vector<int> topologicalOrder) {

        bool flag = false;
        for (int i = 0; i < vertices; i++) {
            if ( !visited[i] && incomingEdges[i] == 0 ) {               
                list<int>::iterator it = adjList[i].begin();
                for (; it != adjList[i].end(); it++) 
                    incomingEdges[*it]--;
                
                visited[i] = true;
                topologicalOrder.push_back(i);

                allTopologicalSortsUtil(visited, topologicalOrder);

                visited[i] = false;
                topologicalOrder.erase(topologicalOrder.end() - 1);

                for (it = adjList[i].begin(); it != adjList[i].end(); it++)
                    incomingEdges[*it]++;

                flag = true;

            }
        }

        if ( !flag ) {
            for (int j = 0; j < topologicalOrder.size(); j++)
                cout << topologicalOrder[j] <<" ";
            cout << endl;
        }          
    }

    void allTopologicalSorts() {
        vector<int> topologicalOrder;
        allTopologicalSortsUtil(visited, topologicalOrder);
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

    cout << "All possible topological sorts" << endl;
    g->allTopologicalSorts();
}
