#include <iostream>
#include <string>

using namespace std; 

bool dictionary_search(string t) {  
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","love","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++) {
        if (dictionary[i].compare(t) == 0)
            return true;
    }
    return false;
}

void word_break(string s, int n, string split) {
    for (int i = 1; i <= n; i++) {
        string t = s.substr(0, i);
        if (dictionary_search(t)) {
            if (i == n) {
                split += t;
                cout << split << endl;
                return;
            }
            word_break(s.substr(i, n - i), (n - i), split + t + " ");
        }
    }
}

void word_break(string s) {
    word_break(s, s.size(), "");
}

int main(int argc, char **argv) {
    string s; 
    cin>>s;
    word_break(s);
}
