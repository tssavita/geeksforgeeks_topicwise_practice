#include <iostream>
#include <string>

using namespace std;

int min(int a, int b) {
    return a < b? a : b;
}

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int edit_distance(string s1, string s2, int i_s1, int i_s2) {
    if (i_s1 == 0)
        return i_s2;
    else if ( i_s2 == 0)
        return i_s1;
    
    if (s1[i_s1-1] == s2[i_s2-1])
        return edit_distance(s1, s2, i_s1-1, i_s2-1);
    else 
        return 1 + min(edit_distance(s1, s2, i_s1, i_s2-1), edit_distance(s1, s2, i_s1-1, i_s2-1), edit_distance(s1, s2, i_s1-1, i_s2));
}

int main(int argc, char ** argv) {
    string s1 = "";
    string s2 = "";

    getline(cin, s1);
    getline(cin, s2);

    cout << edit_distance(s1, s2, s1.size()-1, s2.size()-1);
}
