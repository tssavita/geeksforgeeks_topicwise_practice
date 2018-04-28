#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node *prev;
        node *next;
        node() {}
        node(int d): data(d), prev(NULL), next(NULL) {}
        node(int d, node *p, node *n): data(d) {
            prev = new node;
            prev = p;
            next = new node;
            next = p;
        }
};


void treetodll(node *root, node *head_ref) {
    if (root == NULL)
        return;

    cout << root->data << " ";

    treetodll(root->next, head_ref);
    root->next = head_ref;

    if (head_ref != NULL)
        head_ref->prev = root;

    head_ref = root;
    treetodll(root->prev, head_ref);
}

/* void print() {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}*/

void print(node *t) {
    cout << "entered here";
    node *temp = t;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    node* root = new node(5);
    root->prev = new node(3);
    root->next = new node(6);
    root->prev->prev = new node(1);
    root->prev->next = new node(4);
    root->next->next = new node(8);
    root->prev->prev->prev= new node(0);
    root->prev->prev->next = new node(2);
    root->next->next->prev = new node(7);
    root->next->next->next = new node(9);

    node *h = NULL;
    treetodll(root, h);

    print(h);
}
