# Types of Graphs

## Connected Graphs

* Strongly Connected Graphs are ones in which any two vertices are connected. 
* In a directed graph there are multiple ways to detect if the graph is strongly connected or not: 
    * Floyd-Warshall algorithm of shortest path, with time complexity - O(V^3)
    * Doing DFS or BFS v times from each vertex and checking if every vertex gets visited or not. O(v * (v+e))
    * Using the Strongly Connected Components graph:
        * Checking if each vertex v can be reached from other vertices and every other vertex can be reached from vertexx v. O(v + e).

