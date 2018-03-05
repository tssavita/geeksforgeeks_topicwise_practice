#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long int fibonacci(int n, long long int result[]) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else 
        result[n] = fibonacci(n-1, result) +
                    fibonacci(n-2, result);

    return result[n];
}

int main(int argc, char ** argv) {
    int fib_limit;
    cin>>fib_limit;

    long long int result[fib_limit];

    cout << fibonacci(fib_limit, result);
}
