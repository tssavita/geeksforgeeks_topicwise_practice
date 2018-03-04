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

### Routing Protocols

The Bellman-Ford algorithm is used in __distance vector routing algorithms__, like __Routing Information Protocol(RIP)__. The algorithm is run on each router within an __Autonomous System__*(An Autonomous System is a collection of connected IP routing prefixes that are controlled by one or more network operators on behalf of an administrative entity, that has a clear routing policy to the Internet. It is also a collection of IP networks owned by the Internet Service Provider)*. In a distributed variant of the Bellman-Ford algorithm, 
* Each node calculates the shortest path between itself and every other node in the AS.
* Each node distributes this table with its neighbouring nodes. 
* When it receives a table from its neighbour, it updates its own table if it finds a shorter path to a node from the table it received. 

### Network Flow Analysis

The Bellman-Ford algorithm stops finding the shortest path when it finds a negative edge cycle. This feature can be used for __cycle-cancelling__ techniques.

#### Negative weights and negative cycles

A negative cycle is one with edges whose weights add up to a negative weight.

* Dijkstra's algorithm to find the shortest path does not work when the weight of the edge is negative. 
* Dijkstra's algorithm to find the shortest path does not work when there are negative edge cycles. 
* Bellman-Ford algorithm helps detect the presence of negative edge cycles. 

### Distributed system applications 

* Bellman-Ford algorithm works better for distributed systems because the edges are traversed instead of finding a vertex with the minimum distance each time. 

## Disadvantages

Some disadvantages of the Bellman-Ford algorithm are:

* It does not scale well to accommodate the network changes. 
* __Count to Infinity Problem__ - This algorithm falls prey to loops during the table update process. Consider a subnet from a graph: A <- B <- C. During the vector update process, since router A is down, B does not receive a vector update from A. In the mean time, when B receives an updated table from C, B has no way to find out if the path from C to A is through B itself or not. B sees that its reach to A which was 1 earlier is not possible anymore but C sends reach cost to A = 2, to B. Now B updates its own table value for cost to reach A as 2 + 1 = 3. Then B distributes this to C and C updates its cost of reachability to C as 4, and this happens back and forth between B and C. This goes up to infinity and the Bellman-Ford algorithm corrects itself, using the relaxation property. 

## Sources 

* [http://www.cse.unsw.edu.au/~cs2011/05s2/assignment4-solutions.pdf](http://www.cse.unsw.edu.au/~cs2011/05s2/assignment4-solutions.pdf)
* [https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
* [https://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/](https://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/)
* [https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/](https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/)
* [https://en.wikipedia.org/wiki/Distance-vector_routing_protocol#Count-to-infinity_problem](https://en.wikipedia.org/wiki/Distance-vector_routing_protocol#Count-to-infinity_problem)
