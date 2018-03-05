# How to solve a Dynamic Problem? 

There are 4 important steps: 

* Find in the problem exhibits features like optimal substructure property and overlapping subproblems. A few examples of problems that qualify as candidates of dynamic programming solution are counting the number of ways to do a particular activity under a given constraint, or maximising or minimising a certain quantity.

* Deciding a state - A state is a set of parameters that uniquely define the position of the solution for a problem. For example, in the Fibonacci problem, the state is the limit n, below which we need to calculate the highest fibonacci result. For the Knapsack problem, the state would be the *index* and *weight* combined together. Needless to say, this has to be minimum so that the space occupied is also minimum. 

* Establishing a relation between the states - Figuring out how the basic recursion would take place by determining how to move from one state to the other. For example, in the case of a problem where we need to calculate the number of ways a n steps can be covered, if a person may take one step, 2 steps or 3 steps at a time,
    * the *state* would be *n*
    * the *relation between states* would be steps(n-1) + steps(n-2) + steps(n-3)
    This solution would however lead to an exponential complexity and this brings us to our next point. 
    
* Using memoization or tabulation - We need to cache the results of the previous solutions calculated in order to avoid repetitive and redundant computation. This could be a top-down approach where we look for whether func(n) value has already been calculated in the table and if not, we calculate it as a function of subproblems. Similarly for their subproblems. In the case of bottom up approach, we start from the least possible value for the state, and work our way up to the highset limit of the state, all the while filling up the caching table. 

## Sources:

* [https://www.geeksforgeeks.org/solve-dynamic-programming-problem/](https://www.geeksforgeeks.org/solve-dynamic-programming-problem/)
