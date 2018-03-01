# Disjoint Set Data Structure

A Disjoint set data structure keeps track of a set of elements partitioned into a number of disjoint subsets. It provides near constant time operations to add new sets and to determine whether elements are in the same set. It finds its application in Kruksal's algorithm for minimum spanning tree formation. 

A Disjoint forest element consists of:
* an id,
* a parent,
* rank(optional; foud only in some algorithms).

# Operations

Operations on the Disjoint Set Data Structure are as follows:

* Makeset
    * Function - Make a new set and add an element with pointer to itself, and rank = 0.
    * Pseudocode - 
```
    function MakeSet(x)
        if x is not already present: 
            add x to disjoint-set tree
            x.parent = x
            x.rank = 0
```
    * time Complexity - O(1)
* find
    * function - Find(x) traverses upwards through the parent pointer of each element, till it finds the element whose parent is itself.
        * This the root of the tree. 
        * The root of a tree is the representative member. a
        * One method to optimize the find is to use _Path Compression_ technique, which flattens the tree on which Find has to be applied and speeds up the process. 
    * pseudocode - 
```
    function Find(x)
        if x != x.parent
            x.parent = Find(x.parent)
        return x.parent
```
    * Time Complexity - Naive approach - O(n)
* Union 
    * Function - Finds if x and y belong to the same root and join them if not. (Given two subsets, Union joins them)
        * The naive method to do the joining is by always making x a child of y or vice versa. But if unchecked, the height of the tree can grow by O(n). 
        * To optimize, a Union *by Rank* is carried out. The shorter tree is joined to the root of the taller tree. This way, it can be made sure that the height of the resulting tree is not taller than the original trees. 
    * Pseudocode - 
    ```
        function Union(x, y)
            xRoot = find(x)
            yRoot = find(y)
            
            if (xRoot == yRoot)
                return
            
            if (xRoot.rank < yRoot.rank)
                xRoot.parent = yRoot
            else if (xRoot.rank > yRoot.rank)
                yRoot.parent = xRoot
            else 
                xRoot.parent = yRoot
                yRoot.rank = yRoot.rank + 1
    ```
    * Time Complexity - Naive Approach O(n)


## Applications 

* Detecting if there exists a cycle in an undirected graph.
* Kruksal's algorithm for minimum spanning tree formation.

## Optimization techniques

- Path compression
- Union by Rank
