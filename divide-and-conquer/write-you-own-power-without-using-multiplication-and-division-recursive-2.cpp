#include <iostream>

using namespace std;

int raise(int base, int power);

int multiply(int base, int power) {
    if (power)
        return (base + multiply(base, power - 1));
    else 
        return 0;
}

int raise(int base, int power) {
    if (power)
        return multiply(base, raise(base, power - 1));
    else 
        return 1;
}

int main(int argc, char ** argv) {
    int base, power;
    cin>>base>>power;

    cout << raise(base, power);
}
