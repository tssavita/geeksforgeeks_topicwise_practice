# Matrix Multiplication

## Naive Method 

The time complexity of the naive method is O(N^3).
```
void multiply(int A[][N], int B[][N], int C[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

## Divide and Conquer

The following are the steps: 

* Divide matrices into N/2 and N/2 
* Calculate following values recursively: 
    a   b       e   f       ae + bg     af + bh
            x           =  
    c   d       g   h       ce + dg     cf + dh

      A           B                  C

The time complexity is O(N^3).

## Divide and Conquer - Strassen's Matrix Multiplication

Time Complexity - O(N^2.8)

There are however, some disadvantages of working with Divide and Conquer: 

* Sparce matrices have special methods assigned for them. 
* Recursion takes more Space complexity. 

## Sources 

* [https://www.geeksforgeeks.org/strassens-matrix-multiplication/](https://www.geeksforgeeks.org/strassens-matrix-multiplication/)

## Improving 
