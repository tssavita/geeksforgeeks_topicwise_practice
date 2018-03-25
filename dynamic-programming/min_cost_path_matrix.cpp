#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <climits>

using namespace std;

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c)
            return a;
        else 
            return c;
    }
    else {
        if (b < c)
            return b;
        else 
            return c;
    }
}

int min_cost(int m, int n, int cost_matrix[3][3]) {
    cout << m << " " << n << endl;
    if (m == 0 && n == 0) 
        return cost_matrix[0][0];
    else if (m < 0 || n < 0)
        return INT_MAX;
    else 
        return min(min_cost(m-1, n, cost_matrix), min_cost(m-1, n-1, cost_matrix), min_cost(m, n-1, cost_matrix)) + cost_matrix[m][n];
}

int main(int argc, char ** argv) {
    int cost_matrix[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

    cout << min_cost(2, 2, cost_matrix);
}
