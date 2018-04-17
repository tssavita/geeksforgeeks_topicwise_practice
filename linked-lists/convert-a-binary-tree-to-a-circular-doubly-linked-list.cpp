#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *left; 
        node *right;
        node() {}
        node(int d): data(d), left(NULL), right(NULL) {}
        node(int d, node *l, node *r): data(d), left(l), right(r) {
            left = new node;
            left = (l != NULL) ? l : NULL;
            right = new node;
            right = (r != NULL) ? r : NULL;
        }
};

class cd_ll {
    public: 
        node *head; 
};
