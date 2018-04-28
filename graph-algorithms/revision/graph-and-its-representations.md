# Graph and its Representations

* A Graph is a data structure that consist of two components:
    * A finite set of vertices, also called nodes
    * A finite set of ordered pair (u,v) called an edge. In a directed graph, (v,u) is not the same edge. 

## Applications:

Graphs are used to model different types of relations in physical, biological, social and information systems. Many practical problems can be solved by representing them as graphs. The term networks, roughly translates to a graph in which attributes are associated with notes and edges. 

## Common representations of a Graph: 
    * Adjacency Matrix
        * 2D Array of size V x V, where V is the number of vertices.
        * If adj[i][j] = 1, it means that there is an edge between nodes i and j. 
        * If adj[i][j] = w, it means that w is the weight of the edge between nodes i and j.
        * Pros:
            * Easy to implement
            * Removing and adding an edge operations, take O(1) time. 
            * Checking if there exists and edge between u and v, takes O(1) time as well.
        * Cons:
            * Consumes more space than required - O(V^2), even if graph is sparse.
            * Adding a vertex takes O(V^2) time. 
    * Adjacency List
        * An array of linked lists, where size of the array is equal to the number of vertices.
        * An array element, arr[i], contains a list of nodes with which node i has a direct edge. 
        * The weights can also stored in an extra field in the nodes of linked lists.
Some other representations are Incidence Matrix and Incidence List.

