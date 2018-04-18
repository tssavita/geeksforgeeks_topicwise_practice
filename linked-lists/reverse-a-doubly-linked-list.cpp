#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *prev;
        node *next;
        node() {}
        node(int d): data(d), prev(NULL), next(NULL) {}
        node(int d, node *l, node *r): data(d) {
            prev = new node;
            prev = (l != NULL) ? l : NULL;
            next = new node;
            next = (r != NULL) ? r : NULL;
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
            while (temp->next != NULL) 
                temp = temp->next; 
            temp->next = newnode;
            newnode->prev = temp;
        }

        void prepend(int key) {
            node *newnode = new node(key, NULL, NULL);
            newnode->next = head;
            if (head != NULL) 
                head->prev = newnode;
            head = newnode;
        }

        void reverse() {
            if (head == NULL)
                return;

            node *curr = head, *temp = NULL;
            while (curr != NULL) {
                temp = curr->prev; 
                curr->prev = curr->next; 
                curr->next = temp; 
                curr = curr->prev; 
            }
            if (temp != NULL)
                head->prev = temp->prev;
        }

        void print() {
            node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next; 
            }
        }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    dl_list *dll = new dl_list;
    for(int i = 0; i < n; i++) {
        int t; 
        cin>>t;
        dll->append(t);
    }
    dll->reverse();
    dll->print();
}
