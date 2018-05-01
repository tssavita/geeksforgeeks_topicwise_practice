#include <iostream>
#include <list>
#include <stack>

using namespace std; 

int count = 0;

class edge {
    public: 
        int u, v; 
        edge() {}
        edge(int u1, int v1): u(u1), v(v1) {}
};

class Graph {
    public: 
        int vertices; 
        int edges;
        list<int> *adjlist;

        Graph() {}

        Graph(int v): vertices(v) {
            adjlist = new list<int>[vertices];
        }

        void addEdge(int u, int v) {
            adjlist[u].push_back(v);
            edges++;
        }

        void DFSUtil(int i, int *disc, int *low, int *parent, list<edge> e) {
            static int timevar = 0; 
            disc[i] = low[i] = ++timevar;
            int children = 0; 

            list<int>::iterator it;
            for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                int v = *it;
                if (disc[v] == -1) {
                    children++;
                    parent[v] = i;
                    e.push_back(edge(i, v));
                    DFSUtil(i, disc, low, parent, e);
                    low[i] = min(low[i], low[v]);
                    if ((disc[i] == 1 && children > 1) || (disc[i] > 1 && low[v] >= disc[i])) {
                        while (e.back().u != i || e.back().v != v) {
                            cout << e.back().u << " " << e.back().v;
                            e.pop_back();
                        }
                        cout << e.back().u << " -- " << e.back().v;
                        e.pop_back();
                        count++;
                    }
                }
                else if (v != parent[i] && disc[v] < low[i]) {
                    low[i] = min(low[i], disc[v]);
                    e.push_back(edge(i, v));
                }
            }
        }

        void biConnected() {
            int *disc = new int[vertices];
            int *low = new int[vertices];
            int *parent = new int[vertices];
            list<edge> e;

            for (int i = 0; i < vertices; i++) {
                disc[i] = -1;
                low[i] = -1;
                parent[i] = -1;
            }

            int j;

            for (int i = 0; i < vertices; i++) {
                if (disc[i] == -1) 
                    DFSUtil(i, disc, low, parent, e);

                while ( !e.empty() ) {
                    j = 1; 
                    cout << e.back().u << " - " << e.back().v;
                    e.pop_back();
                }
                if (j == 1) 
                    count++;
            }
        }
};

int main(int argc, char ** argv) {
    int v; 
    cin>>v; 

    Graph *g = new Graph(v);
    g->addEdge(0,1);g->addEdge(1,0);
    g->addEdge(1,2);g->addEdge(2,1);
    g->addEdge(1,3);g->addEdge(3,1);
    g->addEdge(2,3);g->addEdge(3,2);
    g->addEdge(2,4);g->addEdge(4,2);
    g->addEdge(3,4);g->addEdge(4,3);
    g->addEdge(1,5);g->addEdge(5,1);
    g->addEdge(0,6);g->addEdge(6,0);
    g->addEdge(5,6);g->addEdge(6,5);
    g->addEdge(5,7);g->addEdge(7,5);
    g->addEdge(5,8);g->addEdge(8,5);
    g->addEdge(7,8);g->addEdge(8,7);
    g->addEdge(8,9);g->addEdge(9,8);
    g->addEdge(10,11);g->addEdge(11,10);

    g->biConnected();

    cout << count << " ";
}
