#include <iostream> 

using namespace std; 

class ab {
    public:
        int a;
        int b;
        ab() {}
};

int max_chain(ab arr[], int n) {
    int *len = new int[n];
    for (int i = 0; i < n; i++)
        len[i] = 1; 

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i].a > arr[j].b && len[i] < len[j] + 1)
                len[i] = len[j] + 1;
        }
    }

    int max = 0; 
    for (int i = 0; i < n; i++) {
        if (max < len[i])
            max = len[i];
    }

    return max;
}

int main(int argc, char **argv) {
    int n;
    cin>>n;

    ab arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i].a;
        cin>>arr[i].b;
    }

    cout << max_chain(arr, n);
}
