#include <iostream>

using namespace std;

int max(int a, int b) {
    return b ^ ((a ^ b) & (-(a < b)));
}
int min(int a, int b) {
    return a ^ ((a ^ b) & (-(a < b)));
}

int minimum_squares(int length, int breadth) {
    if (length == 1 || breadth == 1)
        return length * breadth;
    else if (length % breadth == 0)
        return length / breadth;
    return length / breadth + minimum_squares(breadth, length % breadth);
}

int main(int argc, char ** argv) {
    int dimension1, dimension2;
    cin>>dimension1;
    cin>>dimension2;
    int l = max(dimension1, dimension2);
    int b = min(dimension1, dimension2);
    cout << minimum_squares(l, b);
}
