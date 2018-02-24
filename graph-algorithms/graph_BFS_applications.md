# Applications of Breadth-first traversal of a graph


1. Shortest Path between any two points - Breadth first search is an algorithm that is convenient to find the shortest path between a source and destination. The destination node is reached with minimum number of edges. 
2. GPS Navigation System - Google Maps uses breadth first search algorithm, using the source location as source node and the destination as destination node in terms of a graph. 
3. Peer to Peer networks - When a client requests for a particular file, the torrent client locates the file by running breadth first search on the client requesting the file.  
4. Social networking websites - Each user profile is treated as a graph node. Two nodes are connected if the owners of the profiles(nodes) are friends. An interesting tidbit is that one can find that any two users on Facebook are connected to each other by at most 5 nodes in between. The famous *Graph Search* feature in Facebook is nothing but a combination of multiple graph algorithms. 
5. Web Crawlers - They can be used to find how many sites can be reached by following links from any particular website.
6. Broadcasting in Network - A broadcast packet in computer networks follows a breadth first search algorithm to reach all nodes.
7. Reachability - Finding if a particular node is reachable from a source. This can be done using depth first traversal as well.
8. Garbage collection from stack([Cheney's algorithm](https://en.wikipedia.org/wiki/Cheney%27s_algorithm)) - The heap is split into equal halves and only one half is used any given point of time. Garbage collection is performed by copying live objects from semispace to the other, which becomes the new heap. 

## Sources:

* [What are some real-life examples of Breadth and Depth First Search?](https://www.quora.com/What-are-some-real-life-examples-of-Breadth-and-Depth-First-Search)
* [Applications of Breadth First Search](https://www.geeksforgeeks.org/applications-of-breadth-first-traversal/)
