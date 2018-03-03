# Dijkstra's Shortest Path Algorithm

This algorithm is similar to Prim's algorithm to determine the Minimum Spanning Tree. There are two sets of vertices. At each point a source vertex is chosen based on minimum distance value. The distance of each other vertex, from this source vertex is updated. 

## Algorithm: 

- Maintain an array that keeps track of vertices that have been added to the shortest path already. 
- Maintain an array of distances for each vertex. Initially, this is
    - zero for a the first vertex that is the source for the shortest path. 
    - INT_MAX for all the other vertices. 
- Go through the distance array and choose a the vertex with minium value, that has not already been added to the shortest path. 
    - Go through the adjacent vertices of the source vertex and update the distance value if it is less than the sum of distance of source vertex and the weight of the edge between source vertex and its adjacent vertex.

## Time Complexity: 

- Using Adjacency Matrix - O(V^2)
- Using Adjacency List - O(E log V)

## Comments: 

- The Dijkstra's algorithm does not work for negative weight edges. The alternative is Bellman-Ford algorithm. 
- By default, the algorithm only maintains if the vertex has been added to the shortest path or not. To keep track of the order in which the vertex is added, another vector can be used. 
