#include <iostream>
#include <string>
#include <vector>

using namespace std;

string common_prefix(string s1, string s2) {
    string prefix;
    for (int i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++) {
        if (s1[i] == s2[j])
            prefix.push_back(s1[i]);
        else 
            break;
    }
    return prefix;
}

string common_prefix(vector<string> strings, int low, int high) {
    if (low == high)
        return strings[low];
    int mid = (low + high) / 2;
    string s1 = common_prefix(strings, low, mid);
    string s2 = common_prefix(strings, mid + 1, high);
    string result = common_prefix(s1, s2);
    cout << result;
    return result;
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    vector<string> strings; 
    for(int i = 0; i <= n; i++) {
        string temp;
        getline(cin, temp);
        strings.push_back(temp);
    }

    cout << common_prefix(strings, 0, n);
}
