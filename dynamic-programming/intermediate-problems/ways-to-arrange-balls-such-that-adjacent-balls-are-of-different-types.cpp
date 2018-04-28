#include <iostream>

using namespace std; 

int count_util(int p, int q, int r, int last) {
    if (p < 0 || q < 0 || r < 0)
        return 0;
    if (p == 1 && q == 0 && r == 0 && last == 0) 
        return 1;
    if (p == 0 && q == 1 && r == 0 && last == 1)
        return 1; 
    if (p == 0 && q == 0 && r == 1 && last == 2)
        return 1; 
    if (last == 0)
        return count_util(p-1, q, r, 1) + count_util(p-1, q, r, 2);
    if (last == 1)
        return count_util(p, q-1, r, 0) + count_util(p, q-1, r, 2);
    if (last == 2)
        return count_util(p, q, r-1, 0) + count_util(p, q, r-1, 1);
}

int count(int p, int q, int r) {
    return count_util(p, q, r, 0) + count_util(p, q, r, 1) + count_util(p, q, r, 2);
}

int main(int argc, char ** argv) {
    int p, q, r;
    cin>>p>>q>>r; 

    cout << count(p, q, r);
}
