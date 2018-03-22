#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class node {
    public:
        char id;
        int frequency; 
        node *left, *right;
        
        node(int i, int f): id(i), frequency(f) {
            left = NULL;
            right = NULL;
        }

        node(int i, int f, node *l, node *r): id(i), frequency(f), left(l), right(r) {}
};

class compare {
    public:
        bool operator() (node *n1, node *n2) {
            return (n1->frequency > n2->frequency) ? true : false;
        }
};

void print(node *n, string s) {
    if (n == NULL)
        return;

    if (n->id != '$') 
        cout << n->id << " " << s;
    print(n->left, s + "0");
    print(n->right, s + "1");
}

void generate_codes(vector<node *> symbols) {
    priority_queue<node *, vector<node *>, compare> pq;

    for (int i = 0; i < symbols.size(); i++) 
        pq.push(symbols[i]);

    while ( pq.size() > 1 ) {
        node *l = pq.top();
        pq.pop();

        node *r = pq.top();
        pq.pop();

        node *internal = new node('$', l->frequency + r->frequency, l, r);
        pq.push(internal);
    }

    print(pq.top(), "");
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    vector<node *> symbols;
    for (int i = 0; i < n; i++) {
//        char id;
//        int frequency;
//        cin>>id;
//        cin>>frequency;
//        node *n = new node(id, frequency);
        node *n = new node(arr[i], freq[i]);
        symbols.push_back(n);
    }

    generate_codes(symbols);
}
