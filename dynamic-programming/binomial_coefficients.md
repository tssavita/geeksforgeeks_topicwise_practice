# Binomial Coefficients

Binomial coefficients are the positive numbers that occur as coefficients in binomial theorem. nCk is read as n choose k - this is the number of ways a subset of size k elements can be chosen from their superset n. 

## History

* The earliest mention of binomial coefficients happened in the tenth century in a commentary by *Halayudha*, on the ancient Sanksrit text *Pingala's Chandaḥśāstra*.
* Around 1150, *Bhaskaracharya* also gave an exposition of binomial coefficients in his book *Līlāvatī*.

## Solving Binomial Coefficients

### Recursive formula 

#### Optimal Substructure

The value of nCk or C(n, k) (as it can also be written as) can be calculated from its subproblems. 

C(n, k) = C(n-1, k-1) + C(n-1, k), for all integers n, k: 1 <= k <= n-1
C(n, 0) = C(n, n) = 1

### Multiplicative formula



### Factorial formula

C(n, k) =   n! / k!(n-k)!   for 0 <= k <= n

#### Applications

* A way to select k elements from a set of n elements.

## Sources 

* [https://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/](https://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/)
