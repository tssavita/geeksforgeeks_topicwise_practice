# Weighted Graphs

For a Weighted graph, one way to represent the Graph would be having a list< pair<int, int> > as the adjacency list. For unweighted graphs, there is only one integer required, to represent the id of the vertex. In a weighted graph, we have another field to represent the weight of the edge between itself and another vertex. 

# Comments: 

In algorithms like Prim's Minimum Spanning Tree algorithm and Dijkstra's shortest path algorithm, there is a separate array used, to keep track of the distance of the vertex(from the other end of the cut or from source respectively). But this array is not initialized as a part of the graph itself, understandably so, because it is used only when specific algorithms are run. 
