# Strongly Connected Components

* A DFS traversal of a graph produces a tree if all vertices are reachable from the starting point, and a forest if not. 
* Depending on which vertex is the starting point, we get a tree or a forest. 
* To get the sequence in which vertices should be visited, we should start with a sink vertex, a vertex that does not have an outgoing vertices. 

## Kosaraju's Algorithm

* The following steps of Kosaraju's SCC algorithm:
    * Do a DFS of the graph and push vertices in a stack when all their adjacent vertices have been visited. 
    * Reverse the graph and find the transpose of the graph.
    * Do a DFS again, of the reversed graph. 

Time Complexity: 

1. DFS - O(V + E)
2. Transposing the Graph - O(V + E)

Some other algorithms to detect strongly connected graphs are as follows: 

* Tarjan's algorithm
* Path-based algorithm

Both of the above algorithms also follow the method of doing a DFS on the graph and maintaining a structure to keep track of vertices visited. 

## Tarjan's Algorithm

* In this algorithm, only 1 DFS traversal of the graph is required. 

