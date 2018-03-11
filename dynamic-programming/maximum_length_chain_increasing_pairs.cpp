#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int maximum_increasing_pair_subsequence(vector<pair<int, int> > arr) {
    int cache_len_subseq[arr.size()];
    for (int i = 0; i < arr.size(); i++)
        cache_len_subseq[i] = 1; 

    for (int i = 0; i < arr.size(); i++)
        cout << cache_len_subseq[i] << " ";

    int i = 1, j = 0;
    for (vector<pair<int, int> >::iterator it = arr.begin()+1; it != arr.end(); it++) {
        cout << it->first << " " << it->second << endl;
        for (vector<pair<int, int> >::iterator jt = arr.begin(); jt != it; jt++) {
            if (it->first > jt->second && cache_len_subseq[i] < cache_len_subseq[j] + 1)
                cache_len_subseq[i] = cache_len_subseq[j] + 1;
            j += 1;
        }
        i += 1;
    }

    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        cout << cache_len_subseq[i] << " ";
        if (max < cache_len_subseq[i])
            max = cache_len_subseq[i];
    }

    return max;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;
    
    vector<pair<int, int> > array_pair;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin>>first;
        cin>>second;
        array_pair.push_back(make_pair(first, second));
    }

    cout << maximum_increasing_pair_subsequence(array_pair);
}
