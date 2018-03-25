# Greedy Algorithms

Greedy algorithms are a paradigm a solution is built up piece by piece and at step, the most optimal subsolution is picked. Greedy algorithm solution is usually an optimization. It can be applied anywhere where the problem exhibits the following activity - At every step, there is the possibility to take the most optimal solution that then becomes the optimal solution for the entire problem. 

It is not a given that the Greedy algorithm can always be applied. If a Greedy solution is able to solve a problem, then it is the most efficient solution because it performs better than Dynamic Programming.

## Applications

* Prim's Minimum Spanning Tree Algorithm - In Prim's algorithm, the aim is to create a minimum spanning tree by picking edges one by one. At each point, the minimum weighing edge is picked that does not cause a cycle in the MST.
* Kruskal's Minimum Spanning Tree - In Kruskal's algorithm, again the aim is to form a minimum spanning tree, by picking one edge at time, that weighs the minimum and does not cause a cycle. 
* Dijkstra's shortest path algorithm - This is very similar to Prim's MST algorithm and at each point, it picks the next vertex, the value of whom is the smallest. The value depends on the weight of the cut. 
* Huffman Coding - A lossless compression technique that assigns a variable length bit code to a character. The greedy choice to assign the least bit code to the most frequently used character.

Some other cases where greedy algorithms are used are to find approximately optimized solutions for Hard problems, for example, the Traveling Salesman Problem where the salesman has to visit each city exactly once with the shortest cost. This step is to get an approximately optimal solution. 

A common problem set for which greedy algorithms are used as a solution is the Activity Selection Problem. 
