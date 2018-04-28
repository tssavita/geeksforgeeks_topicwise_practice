#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *left;
        node *right;
        node() {}
        node(int d): data(d), left(NULL), right(NULL) {}
        node(int d, node *p, node *n): data(d) {
            left = new node;
            left = p;
            right = new node;
            right = n;
        }
};

class dl_list {
    public:
        node *head;

        dl_list() {}

        void append(int key) {
            node *newnode = new node(key);
            if (head == NULL) {
                head = newnode;
                return;
            }

            node *temp = head;
            while (temp->right != NULL) 
                temp = temp->right; 
            temp->right = newnode;
            newnode->left = temp;
        }
};

node *concatenate(node *l, node *r) {

    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    node *llast = l->left;
    node *rlast = r->left;
    l->right = r;
    r->left = llast;
    l->left = rlast;
    r->right = l;

    return l;
}

node *btreelistconvert(node *root) {
    if (root == NULL)
        return NULL;

    node *l = btreelistconvert(root->left);
    node *r = btreelistconvert(root->right);

    root->left = root->right = root; 
    
    return concatenate(concatenate(l, root), r);
}

void print_ll(node *n) {
    node *temp = n;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void print_cl(node *n) {
    node *temp = n;
    while (temp != n) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main(int argc, char ** argv) {
    int n; 
    cin>>n; 

    node *dll = new node(10);
    dll->left = new node(12);
    dll->right = new node(15);
    dll->left->left = new node(25);
    dll->left->right = new node(30);
    dll->right->left = new node(36);

    print_ll(dll);

    node *cdll = btreelistconvert(dll);
    print_cl(cdll);
}
