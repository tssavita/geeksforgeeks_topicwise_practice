#include <iostream>

using namespace std; 

int raise(int base, int power) {
    if (power == 0)
        return 1;
    if (power % 2 != 0)
        return base * raise(base, power / 2) * raise(base, power / 2);
    else 
        return raise(base, power / 2) * raise(base, power / 2);
}

int main(int argc, char ** argv) {
    int base, power;
    cin>>base>>power;

    cout << raise(base, power);
}
