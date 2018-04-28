#include <iostream>
#include <vector>

using namespace std;

void combi_two_times_util(vector<int> &arr, int value, int n) {
    if (value > n) {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        return;
    }
    for (int i = 0; i < 2 * n; i++) {
        if (arr[i] == -1 && i + value + 1 < (n * 2) && arr[i + value + 1] == -1) {
            arr[i] = value;
            arr[i + value + 1] = value;

            combi_two_times_util(arr, value + 1, n);

            arr[i] = -1;
            arr[i + value + 1] = -1;
        }
    }

}

void combi_two_times(int n) {
    vector<int> arr(2 * n, -1);

    combi_two_times_util(arr, 1, n);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    combi_two_times(n);
}
