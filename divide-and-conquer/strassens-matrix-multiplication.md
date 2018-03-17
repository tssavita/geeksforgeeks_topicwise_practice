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

The recursive relation is as follows: 
```
T(N) = 8T(N/2) + O(N^2)
```
The time complexity is O(N ^ log 8) =O(N ^ 3).

## Divide and Conquer - Strassen's Matrix Multiplication

Time Complexity - O(N^2.8)

The Strassen's Matrix Multiplication is similar to Divide and Conquer method explained above, in that this method too divides a matrix into 4 N/2 x N/2 submatrices. However, it reduces in the number of recursive calls from 8 in the previous method to 7. The relation between the two matrices: 

    a   b       e   f       p4 + p6 + p5 - p2       p1 + p2
            x           =   
    c   d       g   h           p3 + p4         p1 - p3 + p5 - p7

where,

p1 = a * (f - h)
p2 = h * (a + b)
p3 = e * (c + d)
p4 = d * (g - e)
p5 = (a + d) * (e + h)
p6 = (b - d) * (g + h)
p7 = (a - c) * (e + f)

The recursive relation is as follows:
```
T(N) = 7T(N/2) + O(N^2)
```
The time complexity here is O(N ^ log 7) ~ O( N ^ 2.8074), which is slightly better than the previous method. There are however, some disadvantages of working with Divide and Conquer: 

* Sparse matrices have special methods assigned for them. 
* Recursion takes more Space complexity. 

## Sources 

* [https://www.geeksforgeeks.org/strassens-matrix-multiplication/](https://www.geeksforgeeks.org/strassens-matrix-multiplication/)
