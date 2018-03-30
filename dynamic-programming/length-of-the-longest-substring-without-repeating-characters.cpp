#include <iostream>
#include <string>

using namespace std; 

int max_length_unique_char(string s) {
    int *prev = new int[s.size()];
    for (int i = 0; i < s.size(); i++) 
        prev[i] = -1; 

    prev[s[0]] = 0;
    int curr_length = 1; 
    int max_length = 1;

    for (int i = 0; i < s.size(); i++) {
        int prev_index = prev[s[i]];
        if (prev_index == -1 && (i - curr_length > prev_index))
            curr_length++;
        else {
            if (curr_length > max_length)
                max_length = curr_length;
            curr_length = i - prev_index;
        }
        prev[s[i]] = i;
    }

    if (curr_length > max_length)
        max_length = curr_length;
    return max_length; 
}

int main(int argc, char **argv) {
    string s;
    getline(cin, s);

    cout << max_length_unique_char(s);
}
