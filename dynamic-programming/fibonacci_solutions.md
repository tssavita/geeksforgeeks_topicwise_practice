# Different ways to get the n-th Fibonacci Number

There are multiple ways to extract the n-th Fibonacci number

## Solution 1: The Recursive Algorithm

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

### Space Complexity: O(n)

There are two types of spaces that one needs to take into account:

* Auxiliary Space: This is the temporary extra space used by the local variables of an algorithm.
* Stack Space: This is the space aoccupied by the algorithm by its input size.

Especially in the case of recursion, there is also the space to considered, that is occupied by current recursive calls. Each recursive call takes a constance space. In the recursive tree, the length could be at least n times long. So, the space complexity could be O(n) *at the least*. The memory occupied by a recursive function could be generalized as O(recursive depth). It depends on the number of return statements because each function call will be stored on the program stack.

## Solution 2: Dynamic Programming: A bottom up algorithm

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

## Solution 3: A bottom up algorithm without caching previous results

### Code
```
int fibonacci(int n) {
    int a = 0;
    int b = 1; 
    int c;
    for (int i = 0; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c;
}
```
### Time Complexity: O(n)

The time complexity for this algorithm is O(n), owing to its iterative functioning. It has to be noted that it uses four statements and hence it is slower than Algorithm 2. However, using the big "O" notation, allows one to ignore the speed of execution based since it does not depend on the number of lines.

### Space Complexity: O(1)

The algorithm uses a constant memory. 

## Solution 4: Matrix Exponentiation

### Code
```
int fibonacci(int n) {
    int M[2][2] = {{1, 1}, {0, 1}};
    for (int i = 1; i < n; i++) {
        M = M * {{1, 1}, {1, 0}};
    }
    return M[0][0];
}
```
### Time Complexity: O(n)

The time complexity here, is O(n) as it is an iterative solution. 

### Space Complexity: O(1)

There is only constance space used, the space does not grow depending on the input. 

## Solution 5: Matrix Exponentiation Optimized

### Code
```
void multiply(int F[2][2], int M[2][2]) {
    int w = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int x = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int y = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int z = F[1][0] * M[0][1] + F[1][1] * M[1][1]
}

void power(int F[2][2], int n) {
    if (n == 0 || n == ) 
        return;
    int M[2][2] = {{1, 1}, {1, 0}};
    power(F, n/2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

int fibonacci(int n) { 
    int M[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
        return 0;

    power(F, n-1);

    return F[0][0];
}
```
### Time Complexity: O(log n)

The time complexity here, because the number of times recursive calls gets halved by two at each depth. 

### Space Complexity: O(1) 

Constant time.

## Sources:

* [http://www.ics.uci.edu/~eppstein/161/960109.html](http://www.ics.uci.edu/~eppstein/161/960109.html)
* [https://stackoverflow.com/questions/43298938/space-complexity-of-recursive-function](https://stackoverflow.com/questions/43298938/space-complexity-of-recursive-function)
