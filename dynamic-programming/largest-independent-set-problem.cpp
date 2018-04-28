#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *left; 
        node *right;
        node() {}
        node(int d): data(d), left(NULL), right(NULL) {}
};

int liss(node *root) {
    if (root == NULL)
        return 0; 

    int excluded = liss(root->left) + liss(root->right);

    int included = 1; 
    if ( root->left )
        included += liss(root->left->left) + liss(root->left->right);
    if ( root->right )
        included += liss(root->right->left) + liss(root->right->right);

    return max(included, excluded);
}

int main(int argc, char **argv) {
    node *n = new node(10);
    n->left = new node(20);
    n->right = new node(30);
    n->left->left = new node(40);
    n->left->right = new node(50);
    n->left->right->left = new node(70);
    n->left->right->right = new node(80);
    n->right->right = new node(60);

    cout << liss(n);
}
