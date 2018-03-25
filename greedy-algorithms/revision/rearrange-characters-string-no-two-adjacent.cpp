#include <iostream>
#include <string>
#include <queue>
#include <assert.h>

#define MAX_CHAR 256

using namespace std;

class Key {
    public:
        char c;
        int freq;

        Key(int c1, int f1): c(c1), freq(f1) {}

        bool operator< (const Key k1) const {
            return freq < k1.freq;
        }
};

string rearranged_string(string input) {
    assert(input.size() != 0);

    int char_count[MAX_CHAR] = {0};
    for (int i = 0; i < input.size(); i++) 
        char_count[input[i] - 'a']++;

    priority_queue<Key> pq;
    for (char c = 'a'; c < 'z'; c++) {
        if (char_count[c - 'a']) {
            const Key k(c, char_count[c - 'a']);
            pq.push(k);
        }
    }

    string r_string = ""; 
    Key prev('#', -1);
    while ( !pq.empty() ) {
        Key temp = pq.top();
        r_string += temp.c;
        pq.pop();

        if (prev.freq > 0)
            pq.push(prev);

        prev = temp;
        prev.freq--;
    }

    return r_string;
}

int main(int argc, char ** argv) {
    string s;
    getline(cin, s);

    cout << rearranged_string(s);
}
