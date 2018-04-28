#include <iostream>
#include <cstring>

using namespace std; 

int max(int a, int b) {
    return a > b ? a : b;
}

int choose_tasks(int *high, int *low, int n) {
    if (n <= 0)
        return 0; 
    int tasks[n+1];
    memset(tasks, 0, n);
    tasks[1] = high[0];
    for (int i = 2; i <= n; i++) {
        tasks[i] = max(high[i-1] + tasks[i-2], low[i-1] + tasks[i-1]);
    }

    return tasks[n];
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    int *high = new int[n];
    for (int i = 0; i < n; i++)
        cin>>high[i];
    int *low = new int[n];
    for (int j = 0; j < n; j++)
        cin>>low[j];

    cout << choose_tasks(high, low, n);
}
