#include <iostream>

using namespace std;

int find_power(int base, int power) {
    if (power == 0)
        return 1;
    else if (power % 2 == 0)
        return find_power(base, power/2) * find_power(base, power/2);
    else 
        return base * find_power(base, power/2) * find_power(base, power/2);
}

int main(int argc, char ** argv) {
    int x;
    cin>>x;

    int n;
    cin>>n;

    cout << find_power(x, n);
}
