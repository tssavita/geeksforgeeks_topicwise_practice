#include <iostream>
#include <vector>
#include <pair>

using namespace std;

class Graph {
    public:
        int vertices; 
        list< pair<int,int> > *vw;
        Graph() {}
        Graph(int v): vertices(v) {}
};

bool k_paths(int src, int k, vector

void addedge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int main(int argc, char ** argv) {
    int v;
    cin>>v;

    Graph *g = new Graph(v);
    cout << ;
}
