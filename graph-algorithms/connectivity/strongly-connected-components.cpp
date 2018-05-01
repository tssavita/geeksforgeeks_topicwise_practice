#include <iostream>
#include <cstring>
#include <list>
#include <stack>

using namespace std; 

class Graph {
    public: 
        int vertices; 
        list<int> *adjlist;
        
        Graph() {}
        
        Graph(int v): vertices(v) {
            adjlist = new list<int>[vertices]; 
        }

        void addEdge(int u, int v) {
            adjlist[u].push_back(v); 
        }

        void DFSStack(int v, bool *visited, stack<int> &order) {
            visited[v] = true;

            list<int>::iterator it;
            for (it = adjlist[v].begin(); it != adjlist[v].end(); it++) {
                if ( !visited[*it] )
                    DFSStack(*it, visited, order);
            }

            order.push(v);
        }

        void DFSPrint(int v, bool *visited) {
            visited[v] = true;
            cout << v << " ";

            list<int>::iterator it;
            for (it = adjlist[v].begin(); it != adjlist[v].end(); it++) {
                if ( !visited[*it] )
                    DFSPrint(*it, visited);
            }
        }

        Graph *transpose() {
            Graph *r = new Graph(vertices);
            for (int i = 0; i < vertices; i++) {
                list<int>::iterator it;
                for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                    r->adjlist[*it].push_back(i);
                }
            }

            return r;
        }

        void SCC() {
            stack<int> order;
            bool *visited = new bool[vertices];
            memset(visited, false, vertices);

            for (int i = 0; i < vertices; i++) {
                if ( !visited[i] )
                    DFSStack(0, visited, order);
            }

            Graph *rev = transpose();        
            memset(visited, false, vertices);
            
            while ( !order.empty() ) {
                int v = order.top();
                order.pop();

                if ( !visited[v] ) {
                    rev->DFSPrint(v, visited);
                    cout << endl;
                }
            }
        }
};

int main(int argc, char ** argv) {
    int v; 
    cin>>v;

    Graph *g = new Graph(v);
    g->addEdge(1, 0);
    g->addEdge(0, 2);
    g->addEdge(2, 1);
    g->addEdge(0, 3);
    g->addEdge(3, 4);

    g->SCC();
}
