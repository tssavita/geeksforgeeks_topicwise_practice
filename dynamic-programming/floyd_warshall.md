# Floyd Warshall Algorithm

* To find the shortest paths between all pairs of vertices in the graph. 
* Time Complexity = O(V^3)
* Exhibits optimal substructure property
    * Pick up each vertex as the source and express its shortest path using every other vertex in the graph
    * There could be two possibilities: 
        * The intermediate vertex is not present in the shortest path from source to destination, in which case, the shortest path remains untouched. 
        * The intermediate vertex is present in the shortest path and there for the shortest path from source to destination becomes a sum a shortest path from source to intermediate vertex and from intermediate vertex to destination vertex. 
