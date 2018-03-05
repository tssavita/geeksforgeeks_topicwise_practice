# Different ways to get the n-th Fibonacci Number

There are multiple ways to extract the n-th Fibonacci number

## The Recursive Algorithm

Code:

```
int fibonacci(int n) {
    if (n == 0 || n == 1)
        n;
    return fibonacci(n-1) + fibonacci(n-2);
}

```

Time Complexity:

Space Complexity: 

In the case of recursion, there are two types of spaces that one needs to take into account:

* Auxiliary Space: This is the temporary extra space used by the local variables of an algorithm.
* Stack Space: This is the space aoccupied by the algorithm by its input size.

## Dynamic Programming: A bottom up algorithm

However at this point, we need to draw attention to the fact that we are not only concerned about improving the time complexity, but we also need to optimize the space complexity. In fact, even if a program takes a lot of time to run it, we may still be able to execute it, but if takes a lot of memory, we may not even be able to run it. Using a caching mechanism to store the value of all the subproblems is not the most efficient way of using space complexity. 

* A bottom up algorithm without caching previous results
* Matrix Exponentiation
* Matrix Exponentiation Optimized

Sources:

* [http://www.ics.uci.edu/~eppstein/161/960109.html](http://www.ics.uci.edu/~eppstein/161/960109.html)
