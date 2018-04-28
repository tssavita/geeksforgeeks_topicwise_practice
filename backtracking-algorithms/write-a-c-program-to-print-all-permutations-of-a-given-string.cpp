#include <iostream>
#include <string>

using namespace std; 

void swap(char *a, char *b) {
    char *temp = a;
    a = b; 
    b = temp;
}

void permute(string s, int start, int end) {
    if (start == end) {
        cout << s << endl; 
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(s.at(start), s.at(i));
        permute(s, start + 1, end);
        swap(s.at(start), s.at(i));
    }
}

int main(int argc, char ** argv) {
    string s;
    getline(cin, s);

    permute(s, 0, s.size() - 1);
}
