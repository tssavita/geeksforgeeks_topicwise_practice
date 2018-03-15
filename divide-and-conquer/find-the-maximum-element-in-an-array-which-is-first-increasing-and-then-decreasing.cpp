#include <iostream> 
#include <vector>

using namespace std;

int find_maximum(vector<int> arr) {
    int max_element = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max_element)
            max_element = arr[i];
    }
    return max_element;
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

    cout << find_maximum(arr);
}
