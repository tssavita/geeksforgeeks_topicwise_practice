#include <iostream>
#include <vector>

using namespace std;

int fixed_point(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == i)
            return i;
    }
    return -1;
}

int main(int argc, char ** argv) {
    vector<int> arr;
    int n;
    cin>>n;
    
    for (int i = 0; i < n; i++)  {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
     
    cout << fixed_point(arr);
}
