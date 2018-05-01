#include <iostream>
#include <list> 
#include <algorithm>
#include <cstring>

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
            adjlist[v].push_back(u);
        }
        
        void rmvEdge(int u, int v) {
            list<int>::iterator itv = find(adjlist[u].begin(), adjlist[u].end(), v);
            *itv = -1;

            list<int>::iterator itu = find(adjlist[v].begin(), adjlist[v].end(), u);
            *itu = -1;
        }

        int DFS(int i, bool *visited) {
            visited[i] = true; 
            int count = 1; 

            list<int>::iterator it;
            for (it = adjlist[i].begin(); it != adjlist[i].end(); it++) {
                if (*it != -1 && !visited[*it])
                    count += DFS(*it, visited);
            }

            return count; 
        }

        bool isValidEdge(int u, int v) {
            int count = 0;
            list<int>::iterator i;
            for (i = adjlist[u].begin(); i != adjlist[u].end(); i++) {
                if (*i != -1)
                    count++;
            }

            if (count == 1)
                return true; 

            bool *visited = new bool[vertices];
            memset(visited, false, vertices);
            int count1 = DFS(u, visited);

            rmvEdge(u, v);

            memset(visited, false, vertices);
            int count2 = DFS(u, visited);

            addEdge(u, v);
            
            return (count1 > count2) ? false : true; 
        }

        void printEulerUtil(int u) {
            list<int>::iterator it;
            for (it = adjlist[u].begin(); it != adjlist[u].end(); it++) {
                if (*it != -1 && isValidEdge(u, *it)) {
                    rmvEdge(u, *it);
                    printEulerUtil(*it);
                }
            }
        }

        void printEulerTour() {
            int u = 0;
            for (int i = 0; i < vertices; i++) {
                if (adjlist[i].size() & 1) {
                    u = i;
                    break;
                }
            }

            printEulerUtil(u);
        }
};

int main(int argc, char ** argv) {
    int v; 
    cin>>v; 

    Graph *g1 = new Graph(v);
    g1->addEdge(0, 1);
    g1->addEdge(0, 2);
    g1->addEdge(1, 2);
    g1->addEdge(2, 3);
    g1->printEulerTour(); 
}
