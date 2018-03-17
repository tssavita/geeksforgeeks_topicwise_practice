#include <iostream>

using namespace std;

int square_root(int x) {
    if (x <= 1)
        return x;
    int result = 1, i = 1;
    while (result < x) {
        if (result == x)
            return result;
        i++;
        result = i * i;
    }
    if (result == x)
        return i;
    else 
        return i - 1;
}

int main(int argc, char ** argv) {
    int x; 
    cin>>x; 

    cout << square_root(x);
}
