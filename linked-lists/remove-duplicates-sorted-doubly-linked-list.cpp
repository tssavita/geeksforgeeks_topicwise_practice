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
            next = n;
        }
};

class dl_list {
    public:
        node *head;
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
            node *newnode = new node(key, NULL, head);
            if (head != NULL)
                head->prev = newnode;
            head = newnode; 
        }

        void remove(int key) {
            cout << "entered here";
            if (head == NULL)
                return; 
            node *temp = head;
            if (head->data == key) {
                head = temp->next;
                head->prev = NULL;
            }
            else {
                
                while (temp->next != NULL && temp->next->data != key) 
                    temp = temp->next;
                cout << temp->data << " ";

                if (temp->next->next != NULL)
                    temp->next->next->prev = temp;
                temp->next = temp->next->next;

            }
        }
        
        void removeall(int key) {
            cout << "key " << key;
            node *temp = head, *n;
            while (temp != NULL) {
                if (temp->data == key) {
                    n = temp->next;
                    remove(key);
                    temp = n;
                }
                else 
                    temp = temp->next;
            }
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
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        dll->append(t);
    }
    dll->print();
    int r;
    cin>>r;
    dll->removeall(r);
    dll->print();
}
