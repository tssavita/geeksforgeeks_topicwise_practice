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

class dl_list {
    public:
        node *head;
        
        dl_list() {}

        void append(int key) {
            if (head == NULL) {
                head = new node(key, NULL, NULL);
                return; 
            }
            node *temp = head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = new node(key, temp, NULL);
            temp->next->prev = temp->next; 
        }

        void at_head(int key) {
            node *newnode = new node(key, NULL, head);
            if (head != NULL)
                head->prev = newnode;
            head = newnode; 
            
        }

        void remove_node(int key) {
            node *temp = head; 
            if (head == NULL) {
                head = head->next; 
                head->prev = NULL;
                delete(temp); 
            }

            node *prev;
            while (temp != NULL && temp->data != key) {
                prev = temp;
                temp = temp->next;
            }
            
            if (temp->next != NULL) {
                prev->next = temp->next;
                temp->next->prev = prev; 
            }
            delete temp; 
        }

        void print() {
            node *newnode = head;
            while (newnode != NULL) {
                cout << newnode->data << " ";
                newnode = newnode->next;
            }
        }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    dl_list *dll = new dl_list;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        dll->append(t);
        dll->at_head(1);
    }

    dll->print();
    dll->remove_node(3);
    dll->print();
}
