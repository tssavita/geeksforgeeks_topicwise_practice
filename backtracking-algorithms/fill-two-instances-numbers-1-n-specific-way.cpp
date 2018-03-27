#include <iostream>

using namespace std; 

void print(int n, int *arr) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

bool fill_after_gaps(int n, int *res, int gaps) {
    if (gaps == 0)
        return true;

    for (int i = 0; i < (2 * n - gaps - 1); i++) {
        if (res[i] == 0 && res[i + gaps + 1] == 0) {
            res[i] = res[i + gaps + 1] = gaps;
            if (fill_after_gaps(n, res, gaps - 1))
                return true;
            res[i] = res[i + gaps + 1] = 0;
        }
    }
    return false;
}

bool fill_after_gaps(int n) {
    int *result = new int[n * 2];
    for (int i = 0; i < n * 2; i++)
        result[i] = 0;

    if (!fill_after_gaps(n, result, n))
        return false; 
    
    print(n * 2, result);
    return true;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    fill_after_gaps(n);
}
