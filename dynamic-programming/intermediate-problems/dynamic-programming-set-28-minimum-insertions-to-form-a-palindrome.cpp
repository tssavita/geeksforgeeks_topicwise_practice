#include <iostream>

using namespace std;

int make_palindrome(string s, int i, int j) {
    if (i > j) 
        return 0; 
    if (i + 1 == j) 
        return s[i] == s[j] ? 0 : 1;
    if (i == j)
        return 0;

    return(s[i] == s[j]) ? make_palindrome(s, i+1, j-1) :
        ( min(make_palindrome(s, i, j-1), make_palindrome(s, i+1, j)) + 1);
}

int main(int argc, char **argv) {
    string s; 
    getline(cin, s);

    cout << make_palindrome(s, 0, s.size()-1);
}
