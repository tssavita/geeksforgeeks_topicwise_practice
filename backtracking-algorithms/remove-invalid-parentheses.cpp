#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

bool is_paranthesis(char c) {
    return (c == '(' || c == ')');
}

bool is_valid(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            count++;
        else if (s[i] == ')')
            count--;
        if (count < 0)
            return false; 
    }
    return (count == 0);
}

void remove_invalid_paranthesis(string s) {
    if (s.size() <= 0)
        return;
    queue<string> q;
    set<string> p;
    q.push(s);
    p.insert(s);
    bool level; 
    while (!q.empty()) {
        s = q.front();
        q.pop();
        if (is_valid(s)) {
            cout << s << endl;
            level = true; 
        }
    
        if (level)
            continue;
        for (int i = 0; i < s.size(); i++) {
            if ( !is_paranthesis(s[i]) )
                continue;
            string r = s.substr(0, i) + s.substr(i + 1);
            if (p.find(r) == p.end()) {
                p.insert(r);
                q.push(r);
            }
        }
    }
}

int main(int argc, char ** argv) {
    string s;
    getline(cin, s);

    remove_invalid_paranthesis(s);
}
