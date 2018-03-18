#include <iostream>

using namespace std; 

void egyptian_fraction(int n, int d) {
    if (n == 0 || d == 0) {
        cout << "0";
        return;
    }

    // Base case where numerator perfectly divides denominator
    if (d % n == 0) {
        cout << "1/" << d/n << endl;
        return;
    }

    // This is not a fraction
    if (n % d == 0) {
        cout << n/d << endl;
    }

    if (n > d) {
        cout << n/d << " + ";
        egyptian_fraction(n % d, d);
    }

    int q = d/n + 1;

    cout << "1/" << q << " + " ;

    egyptian_fraction(n*q-d, d*q);

}

int main(int argc, char ** argv) {
    int num, den;
    cin>>num;
    cin>>den;
    egyptian_fraction(num, den);
}
