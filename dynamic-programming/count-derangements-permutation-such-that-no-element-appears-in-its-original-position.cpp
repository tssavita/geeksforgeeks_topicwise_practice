#include <iostream>

using namespace std; 

int derangements(int n) {
    if (n == 0)
        return 1; 
    if (n == 1)
        return 0;
    if (n == 2)
        return 1; 

    return (n-1) * (derangements(n-1) + derangements(n-2));
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    cout << derangements(n);
}
