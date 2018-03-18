#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minimum_number_of_platforms(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platform_number = 1, intermediate = 1;

    for (int i = 1, j = 0; i < arr.size(); ) {
        if (arr[i] < dep[j]) {
            intermediate++;
            i++;
            if (intermediate > platform_number) 
                platform_number = intermediate;
        }
        else {
            intermediate--;
            j++;
        }
    }

    return platform_number;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    vector<int> dep;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        dep.push_back(a);
    }

    cout << minimum_number_of_platforms(arr, dep); 
}
