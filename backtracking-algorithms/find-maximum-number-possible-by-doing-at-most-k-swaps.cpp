#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void max_swaps(int m, int k) {
    string s = to_string(m);
    int pos = 0; 
    for (int i = 0; i < s.size(); i++) {
        pos = i;
        for (int j = i + 1; j < s.size(); j++) {
            if (j - i > k)
                break;
            if (s[pos] < s[j]) {
                pos = j; 
            }
        }
        for (int j = pos; j > i; j--)
            swap(s[j], s[j - 1]);
    }
    cout << s << endl;
}

int main(int argc, char ** argv) {
    int m, k;
    cin>>m>>k;

    max_swaps(m, k);
}
