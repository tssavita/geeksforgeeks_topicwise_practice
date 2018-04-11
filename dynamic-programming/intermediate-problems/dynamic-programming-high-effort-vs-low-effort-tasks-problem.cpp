#include <iostream>

using namespace std; 

int max(int a, int b) {
    return a > b ? a : b;
}

int choose_task(int *high, int *low, int n) {
    if (n <= 0)
        return 0;

    return max(high[n-1] + choose_task(high, low, n-2), low[n-1] + choose_task(high, low, n-1));
}

int main(int argc, char ** argv) {
    int n; 
    cin>>n;

    int *high = new int[n];
    for (int i = 0; i < n; i++)
        cin>>high[i];

    int *low = new int[n];
    for (int i = 0; i < n; i++)
        cin>>low[i];

    cout << choose_task(high, low, n);
}
