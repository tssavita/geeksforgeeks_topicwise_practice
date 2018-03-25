#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int largest_sum(int a[], int n) {
    int max_so_far = 0, max_till_here = 0;
    for (int i = 0; i < n; i++) {
        max_till_here = max(a[i], max_till_here + a[i]);
        max_so_far = max(max_till_here, max_so_far);
    }

    return max_so_far;
}

int main(int argc, char ** argv) {
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);

    cout << largest_sum(a, n);
}
