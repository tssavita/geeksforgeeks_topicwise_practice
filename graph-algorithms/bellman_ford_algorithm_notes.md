# Bellman-Ford Algorithm

This algorithm is used to find the shortest path between the source and any other vertex in the graph. This algorithm is suited for negative weighing edges as well, unlike Dijkstra's algorithm. It can be used for directed as well as unweighted graph. 

## Time Complexity 

* O(VE)
* It is slower than Dijkstra's algorithm which has a time complexity of O(E log V).

## Graph class representation used: 

```
class Graph {
    int vertices;
    int edges;
    list< pair <pair<int, int>, int> > weighted_edges;
};
```

## Applications 

### Network Flow Analysis

The Bellman-Ford algorithm stops finding the shortest path when it finds a negative edge cycle. This feature can be used for cycle-cancelling techniques.

#### Negative weights and negative cycles

A negative cycle is one with edges whose weights add up to a negative weight.

* Dijkstra's algorithm to find the shortest path does not work when the weight of the edge is negative. 
* Dijkstra's algorithm to find the shortest path does not work when there are negative edge cycles. 
* Bellman-Ford algorithm helps detect the presence of negative edge cycles. 

### Distributed system applications 

* Bellman-Ford algorithm works better for distributed systems because the edges are traversed instead of finding a vertex with the minimum distance each time. 

## Sources 

* [http://www.cse.unsw.edu.au/~cs2011/05s2/assignment4-solutions.pdf](http://www.cse.unsw.edu.au/~cs2011/05s2/assignment4-solutions.pdf)
* [https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
* [
