#include <iostream>

using namespace std; 

int count(string s1, string s2, int m, int n) {
    if (m == 0 && n == 0 || n == 0)
        return 1;
    if (m == 0)
        return 0;

    if (s1[m-1] == s2[n-1])
        return count(s1, s2, m-1, n-1) + count(s1, s2, m-1, n);
    
    else
        return count(s1, s2, m-1, n);
}

int main(int argc, char ** argv) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << count(s1, s2, s1.size(), s2.size());
}
