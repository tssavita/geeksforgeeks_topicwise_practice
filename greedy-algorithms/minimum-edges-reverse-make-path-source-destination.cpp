#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

class Graph {
    int vertices;
    list<int> *adj_list;
    
    public:
    
    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
        adj_list = new list<int>[vertices];
    }

    void add_edge(int src, int dest, int weight) {
        adj_list.push_back(make_pair(make_pair(src, dest)), weight);
    }

    vector<int> shortest_path(int src) {
        set<pair<int, int> > setds;

        setds.insert(make_pair(0, src));

        vector<int> paths(vertices, INT_MAX);

        path[src] = 0;

        while ( !setds.empty() ){
            pair<int, int> temp = setds.top();
            setds.erase(setds.begin());
            
            int u = temp.second;
            list<pair<int, int> >::iterator it; 
            for (it = adj_list[u].begin(); it != adj_list[u].end(); it++) {
                if (path[v] > path[u] + weight) {
                    if (path[u] != INT_MAX && setds.find(make_pair(path[v], v) != setds.end() ))
                        setds.erase(setds.find(make_pair(path[v], v)));
                    path[v] = path[u] + weight;
                    setds.insert(make_pair(path[v], v));
                }
            }
        }
        return path;
    }

    void modified_add_edge(int src, int dest, int weight) {
        edges.push_back(make_pair(make_pair(src, dest)), 0);
        edges.push_back(make_pair(make_pair(dest, src)), 1);
    }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;
}
