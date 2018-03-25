#include <iostream>
#include <vector>

#include "pair_min_max.h"

using namespace std; 

pair_min_max get_min_max(vector<int> arr) {
    pair_min_max p;
    int i = 0;

    if (arr.size() % 2 == 0) {
        if (arr[0] < arr[1]) {
            p.min = arr[0];
            p.max = arr[1];
        }
        else {
            p.min = arr[1];
            p.max = arr[0];
        }
        i = 2;
    }
    else { 
        p.min = arr[0];
        p.max = arr[0];
        i = 1;
    }

    while( i < arr.size() - 1 ) {
        if (arr[i] < arr[i + 1]) {
            if (p.min > arr[i]) 
                p.min = arr[i];
            else if (p.max < arr[i + 1])
                p.max = arr[i+1];        
        }
        else {
            if (p.min > arr[i + 1])
                p.min = arr[i+1];
            else if (p.max < arr[i])
                p.max = arr[i];
        }
        i += 2;
    }

    return p;
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

    pair_min_max p = get_min_max(arr);
    
    cout << p.min << " " << p.max;
}
