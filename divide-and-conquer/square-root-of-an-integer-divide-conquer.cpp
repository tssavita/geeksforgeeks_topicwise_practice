#include <iostream>

using namespace std; 

int square_root(int x) {
    if (x <= 1)
        return 1;
    
    int sqrt_result = 1, low = 1, high = x;

    while (low < high) {
    
        int mid = (low + high) / 2;

        int mid_square = mid * mid;

        if (x == mid_square) 
            return mid;
        else if (x > mid_square) {
            low = mid + 1;
            sqrt_result = mid;
        }
        else 
            high = mid - 1;
    }

    return sqrt_result;
}

int main(int argc, char ** argv) {
    int x;
    cin>>x;

    cout << square_root(x);
}
