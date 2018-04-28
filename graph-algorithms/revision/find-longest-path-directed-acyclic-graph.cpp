#include <iostream>
#include <cstring>
#include <climits>
#include <list>
#include <stack>

using namespace std;

class node {
    int id; 
    int weight;
    public:
        node() {}
        node(int i, int w): id(i), weight(w) {}
        int get_id() {
            return id;
        }
        int get_weight() {
            return weight;
        }
};

class Graph {
    public: 
        int v;
        list<node> *adjlist; 
        Graph() {}
        Graph(int v1): v(v1) {
            adjlist = new list<node>[v];
        }

        void addedge(int s, int d, int w) {
            node newnode(d, w);
            adjlist[s].push_back(newnode);
        }

        void topologicalsortUtil(int i, bool *visited, stack<int> order) {
            visited[i] = true; 

            list<node>::iterator it;
            for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                node t = *it;
                cout << t.get_id() << "id";
                if (!visited[t.get_id()])
                    topologicalsortUtil(t.get_id(), visited, order);
            }
            order.push(i);
        }

        void longest_path(int s) {
            bool *visited = new bool[v];
            memset(visited, false, v);
            
            int *dist = new int[v];
            memset(dist, INT_MIN, v);
            dist[s] = 0;

            stack<int> order;
            
            for (int i = 0; i < v; i++) {
                if (!visited[i])
                    topologicalsortUtil(i, visited, order);
            }

            while ( !order.empty() ) {
                int t = order.top();
                order.pop();
                list<node>::iterator it;
                if (dist[t] != INT_MIN) {
                    for (it = adjlist[t].begin(); it != adjlist[t].end(); it++) {
                        node d = *it;
                        if (dist[d.get_id()] < dist[t] + d.get_weight()) 
                            dist[d.get_id()] = dist[t] + d.get_weight();                        
                    }
                }
            }

            for (int i = 0; i < v; i++) 
                cout << i << " " << dist[i] << endl;
        }
};

int main(int argc, char ** argv) {
    int v, e;

    cin>>v>>e;
    Graph *g = new Graph(v);
    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin>>s>>d>>w;
        g->addedge(s, d, w);
    }
    g->longest_path(1);
}
