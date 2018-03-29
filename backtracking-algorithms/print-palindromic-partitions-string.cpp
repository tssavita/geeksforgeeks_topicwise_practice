#include <iostream>
#include <string>
#include <vector>

using namespace std; 

bool is_palindromic(string s) {
    int start = 0, end = s.size() - 1;
    while (start <= end) {
        if (s[start] != s[end])
            return false;
        start++, end--;
    }

    return true; 
}

void print(vector<vector<string> > partitions) {
    for (int i = 0; i < partitions.size(); i++) {
        for (int j = 0; j < partitions[i].size(); j++)
            cout << partitions[i][j] << " ";
        cout << endl;
    }
}

void palindromic_partitions(string s, vector<string> &temp, vector<vector<string> > & partitions, int index) {
    
    if (index == 0)
        temp.clear();

    vector<string> current = temp; 
    string t; 
    for (int i = index; i < s.size(); i++) {
        t += s[i];
        if (is_palindromic(t)) {
            temp.push_back(t);
            if ((i + 1) < s.size())
                palindromic_partitions(s, temp, partitions, i + 1);
            else 
                partitions.push_back(temp);
            temp = current;
        }
    }
    return;
}

void palindromic_partitions(string s) {
    vector<vector<string> > partitions;
    vector<string> temp;
    palindromic_partitions(s, temp, partitions, 0);
    print(partitions);
}

int main(int argc, char **argv) {
    string s; 
    getline(cin, s);

    palindromic_partitions(s);
}
