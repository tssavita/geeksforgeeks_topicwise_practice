# Minimum Spanning Tree

## Introduction

A Minimum Spanning Tree for a graph is one that connects all vertices of a graph with the set of edges that weigh the minimum. A Spanning Tree for a graph would be the subset of edges that connect all vertices. There may exist several spanning trees for a graph. 

## Different types of implementation 

There are different types of implementations for MST: 
* Prim's Minimum Spanning Tree - While using: 
    * Adjacency Matrix - O(V^2)
    * Adjacency List - O(E log V)
    * #TODO: Check out Prim's MST with a priority queue.
* Kruksal's Algorithm - 
    * Sorting of edges according to their weights takes O(E log E),
    * Iterating through the sorted edges can take O(log V),
    * Total complexity - O(E log E + E log V) = O(E log E)
    * Since E can be almost equal to V^2. So the O(log V) == O(log E).
* Boruvska's Algorithm
    * Time Complexity - O(E log V)
* Steiner Tree 

## Applications of Prim's MST 

Some of the applications of a Minimum Spanning Tree are as follows:

1. Networks - MST can be used in the design of networks. 
    1. Telecommunication wires - Laying down in various cities. 
    2. Ethernet wires - Constructing trees for broadcasting in computer networks. There is the Spanning Tree protocol that is used in ethernet networks. [2] The Spanning Tree Protocol builds a cycle free topology that allows a broadcast message to be sent without causing broadcase radiation(that causes broadcast and multicast floods in the network).

2. Muddy City Problem - Designing paths between all houses in a city, such that all houses are connected and the cost of constructing the paths is minimum. Source - [2]

3. Steiner Graphs - A Steiner graph is a minimum spanning tree constructed out of a subset of vertices from the original graph. Some terminology associated with Steiner graphs: 
        - Terminal vertices - The subset of vertices chosen from the original graph, for which, a Steiner graph needs to be constructed. 
        - Steiner vertices - Those vertices that are not in the subset of vertices for which a Steiner graph has to be constructed, but have to included in the Steiner graph, to complete the minimum spanning tree for the terminal vertices. 

4. Cluster Analysis or Clustering - It is the process of grouping k objects that are similar to each other by some means. This method finds its applications in areas like Data Mining, machine learning, pattern recognition, image analysis, data compression, bioinformatics and computer graphics. Source - [3]

5. Traveling Salesman Problem - The requirement is to use the shortest path that visits all cities once. Source - [1].

## Sources

1. Geeks for Geeks 
2. [http://www.utdallas.edu/~besp/teaching/mst-applications.pdf]<http://www.utdallas.edu/~besp/teaching/mst-applications.pdf>
3. [https://en.wikipedia.org/wiki/Cluster_analysis]<https://en.wikipedia.org/wiki/Cluster_analysis>
