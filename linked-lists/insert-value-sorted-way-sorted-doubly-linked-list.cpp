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
            prev = (p != NULL) ? p : NULL;
            next = new node;
            next = (n != NULL) ? n : NULL;
        }
};

class llist {
    public: 
        node *head;

        llist() {}

        void append(int key) {
            node *newnode = new node(key);
            if (head == NULL) {
                head = newnode;
                return;
            }

            node *temp = head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }

        void sortnappend(int key) {
            node *newnode = new node(key);
            if (head == NULL) {
                head = newnode;
                return;
            }
            else if (key <= head->data) {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            else {
                node *temp = head, *temp_prev = NULL;
                while (temp->next != NULL && temp->next->data < key) 
                    temp = temp->next;
                newnode->next = temp->next;
                if (temp->next != NULL)
                    newnode->prev->next = newnode;
                temp->next = newnode;
                newnode->prev = temp;
            }
        }
        
        void print() {
            node *temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    llist *l = new llist;
    llist *a = new llist;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        l->append(t);
        a->sortnappend(t);
    }
    l->print();
    a->print();
}
