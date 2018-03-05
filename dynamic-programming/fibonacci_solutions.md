# Different ways to get the n-th Fibonacci Number

There are multiple ways to extract the n-th Fibonacci number

## The Recursive Algorithm

### Code:
```
int fibonacci(int n) {
    if (n == 0 || n == 1)
        n;
    return fibonacci(n-1) + fibonacci(n-2);
}
```
### Time Complexity: O(2^n)

For every call of the fibonacci(n), there will be two other fibonacci function calls. This leads to an exponential growth in the number of function calls. This algorithm is extremely slow and for n = 45, it takes about a billion steps.

### Space Complexity: 

There are two types of spaces that one needs to take into account:

* Auxiliary Space: This is the temporary extra space used by the local variables of an algorithm.
* Stack Space: This is the space aoccupied by the algorithm by its input size.

Especially in the case of recursion, there is also the space to considered, that is occupied by current recursive calls. Each recursive call takes a constance space. In the recursive tree, the length could be at least n times long. So, the space complexity could be O(n) *at the least*. The memory occupied by a recursive function could be generalized as O(recursive depth). It depends on the number of return statements because each function call will be stored on the program stack.

## Dynamic Programming: A bottom up algorithm

### Code 
```
int fibonacci(int n) {
    int cache[n+1];
    cache[0] = 0;
    cache[1] = 0;

    for (int i = 2; i <= n; i++) {
        cache[i] = cache[i-1] + cache[i-2];
    }

    return cache[n];
}
```
### Time Complexity: O(n)

Here, the time complexity is improved by taking advantage of the optimal substructure and overlapping subproblems properties, to apply dynamic programming. Now, the algorithm is linear and takes only O(n).

### Space Complexity: O(n)

This algorithm occupies more space than the vanilla recursive algorithm - it uses an array whose size depends on the input, to cache the results of subproblems. 

However at this point, we need to draw attention to the fact that we are not only concerned about improving the time complexity, but we also need to optimize the space complexity. In fact, even if a program takes a lot of time to run it, we may still be able to execute it, but if takes a lot of memory, we may not even be able to run it. Using a caching mechanism to store the value of all the subproblems is not the most efficient way of using space complexity. 

* A bottom up algorithm without caching previous results
* Matrix Exponentiation
* Matrix Exponentiation Optimized

Sources:

* [http://www.ics.uci.edu/~eppstein/161/960109.html](http://www.ics.uci.edu/~eppstein/161/960109.html)
* [https://stackoverflow.com/questions/43298938/space-complexity-of-recursive-function](https://stackoverflow.com/questions/43298938/space-complexity-of-recursive-function)
