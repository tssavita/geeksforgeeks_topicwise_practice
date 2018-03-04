# Bellman-Ford Algorithm

This algorithm is used to find the shortest path between the source and any other vertex in the graph. This algorithm is suited for negative weighing edges as well, unlike Dijkstra's algorithm. It can be used for directed as well as unweighted graph. 

# Negative weights and negative cycles

A negative cycle is one with edges that have a negative weight. 

* Dijkstra's algorithm to find the shortest path does not work when the weight of the edge is negative. 
* Dijkstra's algorithm to find the shortest path does not work when there are negative edge cycles. 
* Bellman-Ford algorithm helps detect the presence of negative edge cycles. 

# Time Complexity 

* O(VE)
* It is slower than Dijkstra's algorithm which has a time complexity of O(E log V).

# Graph class representation used: 

```
class Graph {
    int vertices;
    int edges;
    list< pair <pair<int, int>, int> > weighted_edges;
};
```
