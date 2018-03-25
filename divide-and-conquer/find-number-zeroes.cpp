#include <iostream>
#include <vector>

using namespace std; 

int number_of_zeroes(vector<int> one_zero, int low, int high) {
    if (high < low) 
        return -1;
    int mid = low + (low + high) / 2; 
    if ( (mid == 0) || (one_zero[mid-1] == 1) && (one_zero[mid] == 0) ) 
        return mid; 
    if (one_zero[mid] == 1)
        return number_of_zeroes(one_zero, mid + 1, high);
    else 
        return number_of_zeroes(one_zero, low, mid - 1);
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<int> one_zero;
    for (int i = 0; i < n; i++) {
        int temp; 
        cin>>temp; 
        one_zero.push_back(temp);
    }

    int zeroes = number_of_zeroes(one_zero, 0, one_zero.size() - 1);
    if (zeroes == -1) 
        cout << "No zeroes";
    else 
        cout << one_zero.size() - zeroes;
}
