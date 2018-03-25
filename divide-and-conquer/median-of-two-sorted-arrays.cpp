#include <iostream>
#include <vector>

using namespace std;

int calculate_median(vector<int> arr1, vector<int> arr2) {
    int i = 0, j = 0;
    int m1 = -1, m2 = -1;
    for (int k = 0; k <= arr1.size(); k++) {
        if (i == arr1.size()) {
            m1 = m2; 
            m2 = arr2[0];
            break;
        }
        else if (j == arr2.size()){
            m1 = m2;
            m2 = arr1[0];
            break;
        }
        if (arr1[i] <= arr2[j]) {
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else {
            m1 = m2; 
            m2 = arr2[j];
            j++;
        }
    }

    return (m1 + m2) / 2;
}

int main(int argc, char ** argv) {
    int n; 
    cin>>n;

    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }

    cout << calculate_median(arr1, arr2);
}
