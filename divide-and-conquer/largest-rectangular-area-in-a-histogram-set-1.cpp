#include <iostream>
#include <vector>
#include <climits>

using namespace std; 

int min(int *hist, int i, int j) {
    if (i == -1) 
        return -1;
    if (j == -1)
        return -1;

    return (hist[i] < hist[j])? i : j;
}

int ret_min(int *hist, int *st, int hstart, int hend, int qstart, int qend, int sti) {
    if (qstart <= hstart && qend >= hend)
        return st[sti];

    if (hend < qstart || hstart > qend)
        return -1;

    int mid = hstart + (hend - hstart) / 2; 
    return min(hist, ret_min(hist, st, hstart, mid, qstart, qend, sti * 2 + 1), ret_min(hist, st, mid + 1, hend, qstart, qend, sti * 2 + 2);
}

int ret_min(int *hist, int *st, int st_size, int qstart, int qend) {
    if (qstart < 0 || qend > hend || qend < qstart) 
        return -1;

    return ret_min(hist, st, 0, st_size - 1, qstart, qend, 0);
}

int construct(int *hist, int hstart, int hend, int *st, int sti) {
    if (sti < 0 || sti > (hend - 1) )
        return INT_MAX;

    int mid = hstart + (hend - hstart) / 2;

    st[sti] = min(hist, construct(hist, hstart, mid, st, sti * 2 + 1),
            construct(hist, mid + 1, hend, st, sti * 2 + 2));

    return st[sti];
}

int *construct(int *hist, int size) {
    int *st = new int[2 * size - 1];

    construct(hist, 0, n-1, st, 0);

    return st;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *hist = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>hist[i];
    }

    int *st = construct(hist, n-1);
}
