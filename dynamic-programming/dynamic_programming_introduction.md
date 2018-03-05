# Dynamic Programming 

Dynamic Programming is an algorithmic paradigm used to solve complex problems by breaking them into smaller subproblems, solving and caching the solutions of the subproblems so that they can be reused for solving other problems. Dynamic programming is also often used for optimization of an existing solution to a problem.

One interesting way of seeing dynamic programming is "careful brute force". Careful and brute force are not something that would come together - Oxymoron. 

## History

Dynamic Programming was founded by Richard Bellman. A bit of history - The term dynamic programming was coined by Richard Bellman to hide the fact that he was doing mathematical research. His employee was hateful of the term "research".

## Applications

* __Bioinformatics__ - Dynamic programming is widely used for sequence alignment(*a method of arranging the DNA, RNA and proteins to determing areas that are of similarity, which may be a consequence from functional, structural or evolutionary relationships between sequences*), RNA structure prediction, protein-DNA folding, etc. Some keywords are __nucleosome positioning__ and __transcription factor binding__.

* __Computer Programming__ - There are some properties of a problem that show if Dynamic programming needs to be used: 
    * __Optimal substructure__ - A problem has an optimal substructure property if it can be solved using the optimal solution of its subproblem. 
        * For example, the shortest path calculation has an optimal substructure - The shortest path from p to s(p-> q -> r-> s) would be the shortest path form p -> r + r -> s. The Bellman-Ford and Floyd-Warshall algorithm are examples of dynamic programming.
        * The longest path problem does not have an optimal substructure property. Consider the following picture. The longest path from r -> s is not a combination of the longest path from r -> t and t -> s.
    <p align="center">
        <img src="https://www.geeksforgeeks.org/wp-content/uploads/LongestPath.gif">
    </p>

    * __Overlapping subproblems__ - In dynamic programming, the solutions of subproblems are stored in a table so that the subproblems do not need to be solved repetitively. It makes sense to use dynamic programming only when subproblems are common. For example, dynamic programming is not useful for binary search that does not have any common subproblems, unlike the Fibonacci. There are two ways:
        * __Top-down approach - Memoization__ - An array is initialized that is set to INT_MAX. When we need a solution to a subproblem, we look up the table that stores the results for subproblems. If result is found, then it is returned. If not then it is calculated and stored. 
        * __Bottom-up approach - Tabulation__ -  This method calculates the solution for all possible subproblems, whether or not all these solutions are required or not. 

## Sources 

* [http://www.ics.uci.edu/~eppstein/161/960109.html](http://www.ics.uci.edu/~eppstein/161/960109.html)
* [https://www.youtube.com/watch?v=OQ5jsbhAv_M](https://www.youtube.com/watch?v=OQ5jsbhAv_M)
