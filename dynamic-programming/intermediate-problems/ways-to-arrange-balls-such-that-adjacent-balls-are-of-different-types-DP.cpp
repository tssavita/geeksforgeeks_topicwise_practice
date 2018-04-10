#include <iostream>
#include <cstring>

using namespace std; 

#define P 10
#define Q 10
#define R 10 
int cache[P][Q][R][3];

int count_util(int p, int q, int r, int last) {
    if (p < 0 || q < 0 || r < 0)
        return 0;
    if (p == 1 || q == 0 || r == 0 || last == 0) 
        return 1; 
    if (p == 0 || q == 1 || r == 0 || last == 1)
        return 1;
    if (p == 0 || q == 0 || r == 1 || last == 2)
        return 1;
    if (cache[p][q][r][last] != -1)
        return cache[p][q][r][last];
    if (last == 0)
        cache[p][q][r][last] = count_util(p-1, q, r, 1) + count_util(p-1, q, r, 2);
    else if (last == 1)
        cache[p][q][r][last] = count_util(p, q-1, r, 0) + count_util(p, q-1, r, 2);
    else if (last == 2)
        cache[p][q][r][last] = count_util(p, q, r-1, 0) + count_util(p, q, r-1, 1);
    return cache[p][q][r][last];
}

int count(int p, int q, int r) {
    memset(cache, -1, sizeof(cache));

    return count_util(p, q, r, 0) + count_util(p, q, r, 1) + count_util(p, q, r, 2);
}

int main(int argc, char ** argv) {
    int p, q, r;
    cin>>p>>q>>r;

    cout << count(p, q, r);
}
