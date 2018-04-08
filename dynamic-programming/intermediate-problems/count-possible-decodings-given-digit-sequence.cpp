#include <iostream>

using namespace std;

int count_decodings(string s) {
    if (s.size() == 0)
        return 0;

    int count = 0;

    if (s[s.size()-1] > '0')
        count = count_decodings(s.substr(0, s.size()-1));
    cout << count;

    if (s[s.size()-2] == '1' || (s[s.size()-2] == '2' && s[s.size()-1] < '7'))
        count += count_decodings(s.substr(0, s.size()-2));

    cout << " " << count;

    return count;

}

int main(int argc, char ** argv) {
    string s;
    getline(cin, s);

    cout << count_decodings(s);
}
