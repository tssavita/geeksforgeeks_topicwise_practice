# Eulerian Cycles and Paths

* An Eulerian Cycle in a graph is one that connects all vertices with a non-zero degree. 
* A graph is said to be Eulerian if there exists an Eulerian Cycle in it. 
* A graph is said to be semi-Eulerian if there exists an Eulerian Path in it. 
* An Eulerian Cycle starts and ends on the same node after having visited all other non-zero degree nodes. 
* The Eulerian Cycle is the answer to the question:
> Given a graph, is it possible to construct a path that visits each node exactly once?
* Leonard Euler, a Swiss mathematician, was the one who mathematically proved that the fact that all connected graphs with vertices of even degree have are Eulerian.
* There are two meanings to when a graph is called Eulerian: 
    * The graph has an Eulerian Cycle. 
    * All vertices of the graph have an even degree. 

## Condition for Eulerian Cycle:

* All vertices in the graph should posses an even degree. 

## Condition for Eulerian Path: 

* Either 0 or 2 vertices in the graph, should posses an odd degree and all other vertices should posses and even degree.

## Eulerian Path Applications 

* Eulerian Paths(or trails) are used to reconstruct DNA sequences from its fragments.
* They are also used in CMOS circuit design to find an optical logic gate ordering. 
* They are some algorithms for processing trees, that use the Euler tour of the tree, where each connection(or edge) becomes a pair of arcs.
