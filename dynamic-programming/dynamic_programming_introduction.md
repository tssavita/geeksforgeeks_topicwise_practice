# Dynamic Programming 

Dynamic Programming is an algorithmic paradigm used to solve complex problems by breaking them into smaller subproblems, solving and caching the solutions of the subproblems so that they can be reused for solving other problems. Dynamic programming is also often used for optimization of an existing solution to a problem.

# Applications

* __Bioinformatics__ - Dynamic programming is widely used for sequence alignment(*a method of arranging the DNA, RNA and proteins to determing areas that are of similarity, which may be a consequence from functional, structural or evolutionary relationships between sequences*), RNA structure prediction, protein-DNA folding, etc. Some keywords are __nucleosome positioning__ and __transcription factor binding__.

* __Computer Programming__ - There are some properties of a problem that show if Dynamic programming needs to be used: 
    * __Optimal substructure__ - A problem has an optimal substructure property if it can be solved using the optimal solution of its subproblem. 
        * For example, the shortest path calculation has an optimal substructure - The shortest path from p to s(p-> q -> r-> s) would be the shortest path form p -> r + r -> s. The Bellman-Ford and Floyd-Warshall algorithm are examples of dynamic programming.
        * The longest path problem does not have an optimal substructure property. Consider the following picture. The longest path from r -> s is not a combination of the longest path from r -> t and t -> s.

![Directed cyclic graph](LongestPath.gif)

    * Overlapping subproblems - 
