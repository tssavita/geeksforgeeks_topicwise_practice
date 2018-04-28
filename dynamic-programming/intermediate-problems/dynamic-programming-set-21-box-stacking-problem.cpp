#include <iostream>
#include <algorithm>

using namespace std; 

class box {
    public:
        int h;
        int w;
        int d;
        box() {}
};

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int base_area(box b1, box b2) {
    return (b2.d * b2.w) - (b1.d * b1.w);
}

int max_height(box b[], int n) {
    box rot[n * 3];
    int index = 0;
    for (int i = 0; i < n; i++) {
        rot[index].h = b[i].h;
        rot[index].d = max(b[i].d, b[i].w);
        rot[index].w = min(b[i].d, b[i].w);
        index++;

        rot[index].h = b[i].w;
        rot[index].d = max(b[i].h, b[i].d);
        rot[index].w = min(b[i].h, b[i].d);
        index++;

        rot[index].h = b[i].d;
        rot[index].d = max(b[i].h, b[i].w);
        rot[index].w = min(b[i].h, b[i].w);
        index++;
    }

    n = 3 * n;

    sort(b, b + n, base_area);
    
    int *mh = new int[n];
    for (int i = 0; i < n; i++)
        mh[i] = b[i].h;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (b[i].w < b[j].w && b[i].d < b[j].d &&mh[i] < mh[j] + b[i].h)
                mh[i] = mh[j] + b[i].h;
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < mh[i])
            max = mh[i];
    }
    return max;
}

int main(int argc, char **argv) {
    int n;
    cin>>n;
    
    box b[n];
    for (int i = 0; i < n; i++) {
        cin>>b[i].h;
        cin>>b[i].w;
        cin>>b[i].d;
    }

    cout << max_height(b, n);
}
