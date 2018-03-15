#include <iostream>
#include <climits>
#include <vector>

using namespace std; 

int find_maximum(vector<int> arr, int low, int high) {
    if (low == high)
        return arr[low];
    
    if ( (high == (low + 1)) && (arr[high] >= arr[low]) ) 
        return arr[high];

    if ( (high == (low + 1)) && (arr[high] < arr[low]) )
        return arr[low];

    int mid = (low + high) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid + 1] < arr[mid]) 
        return arr[mid];
    else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) 
        return find_maximum(arr, low, mid-1);
    else 
        return find_maximum(arr, mid+1, high);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> arr; 
    for (int i = 0; i < n; i++) {
        int temp; 
        cin>>temp;
        arr.push_back(temp);
    }

    cout << find_maximum(arr, 0, arr.size()-1);
}
