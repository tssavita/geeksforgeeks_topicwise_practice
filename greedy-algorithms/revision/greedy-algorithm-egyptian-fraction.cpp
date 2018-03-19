#include <iostream>

using namespace std;

void egyptian_fraction(int num, int den) {
    if (den == 0)
        return;

    if (num == 0)
        return;

    if (den % num == 0) {
        cout << "1 / " << (den / num);
        return;
    }

    if (num % den == 0) {
        cout << (num / den);
        return;
    }

    if (num > den) {
        cout << (num / den) << " + "; 
        egyptian_fraction(num % den,  den);
    }

    int temp = den / num + 1;

    cout << "1 / " << temp << " + ";

    egyptian_fraction(((temp * num) - den), temp * den);
    
}

int main(int argc, char ** argv) {
    int num, den;

    cin>>num>>den;

    egyptian_fraction(num, den);
}
