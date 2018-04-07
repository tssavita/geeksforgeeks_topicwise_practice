#include <iostream>
#include <cmath>

using namespace std;

//string max(string s1, string s2) {
//    return s1.size() < s2.size() ? s2 : s1; 
//}

int max_path(int **arr, int n, int x, int y, int p) {
    if (x >= n || y >= n) 
        return 0;
    
    int result = max( max_path(arr, n, x + 1, y, p + 1), max_path(arr, n, x, y + 1, p + 1));

    if (arr[x][y] == 1) 
        return result + pow(2, p);
    
    return result;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int **arr = new int*[n];
    for (int i = 0; i < n; i++) 
        arr[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin>>arr[i][j];
    }

    cout << max_path(arr, n, 0, 0, 0);
}
