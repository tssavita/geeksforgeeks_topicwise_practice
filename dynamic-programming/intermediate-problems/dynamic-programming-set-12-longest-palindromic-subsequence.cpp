#include <iostream>

using namespace std; 

int palindrome(string s, int i, int j) {
    if (i == j)
        return 1; 
    else if (s[i] == s[j] && i + 1 == j)
        return 2;
    else if (s[i] == s[j])
        return 2+palindrome(s, i + 1, j - 1);
    return max(palindrome(s, i + 1, j), palindrome(s, i, j-1));
}

int main(int argc, char ** argv) {
    string s;

    getline(cin, s);

    cout << palindrome(s, 0, s.size()-1);
}
