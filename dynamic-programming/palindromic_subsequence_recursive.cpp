#include <iostream>
#include <string>

using namespace std;

int longest_palindrome(string s, int i, int j) {
    if (s.size() == 0 || i > j)
        return 0;
    else if (i == j)
        return 1; 
    else if (s[i] == s[j])
        return 2 + longest_palindrome(s, i+1, j-1);
    return max(longest_palindrome(s, i+1, j), longest_palindrome(s, i, j-1));
}

int main(int argc, char ** argv) {
    string s1;
    getline(cin, s1);

    cout << longest_palindrome(s1, 0, s1.size()-1);
}
