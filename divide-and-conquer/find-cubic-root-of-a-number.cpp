#include <iostream>

using namespace std; 

double difference(double n, double mid_cube) {
    if (n > mid_cube)
        return n - mid_cube;
    else 
        return mid_cube - n;
}

double cubic_root(double n) {
    int start = 0, end = n;

    double accuracy = 0.0000001;

    while (true) {
    
        double mid = (start + end) / 2;
        double mid_cube = mid * mid * mid; 
        double error = difference(n, mid_cube);

        if (error <= accuracy)
            return mid; 

        if (mid_cube > n)
            end = mid;
        else 
            start = mid;
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    cout << "Find cubic root of " << n;
    cout << cubic_root(n);
}
