#include <iostream>
#include <climits>

using namespace std; 

int min_coins(int *arr, int n, int amount) {
    if (amount == 0)
        return 0; 

    int coins = INT_MAX; 

    for (int i = 0; i < n; i++) {
        if (arr[i] <= amount) {
            int temp = min_coins(arr, n, amount - arr[i]);
            if (temp != INT_MAX && temp + 1 < coins)
                coins = temp + 1; 
        }
    }

    return coins;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int amount;
    cin>>amount;

    cout << min_coins(arr, n, amount);
}
