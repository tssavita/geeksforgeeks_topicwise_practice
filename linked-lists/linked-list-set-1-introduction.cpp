#include <iostream>

using namespace std; 

//TODO
class node {
    public: 
        int data;
        node *next;
        node() {}
        node(int d): data(d), next(NULL) {}
        node(int d, node *n): data(d) {
            next = new node();
            if (n != NULL) {
                next->data = n->data;
                next->next = n->next;
            }
            else {
                next = NULL;
            }
        }
};

class sl_list {
    public:
        node *head; 
        sl_list(): head(NULL) {}
        void append(int key) {
            if (head == NULL) {
                head = new node(key);
                return;
            }
            
            node *temp = head;
            while ( temp->next != NULL ) 
                temp = temp->next;
            temp->next = new node(key);
        }

        void prepend(int key) {
            node *temp = new node(key);
            temp->next = head;
            head = temp;
        }

        void remove(int key) {
            if ( head == NULL )
                return;
            node *prev, *temp = head;
            if (key == head->data) {
                head = temp->next;
                delete temp; 
                return;
            }

            while ( temp != NULL && temp->data != key) {
                prev = temp;
                temp = temp->next;
            }
            
            if (temp == NULL)
                return;

            prev->next = temp->next;
            delete temp; 
        }

        void size() {
            node *temp = head;
            int sz = 0;
            while ( temp != NULL ) {
                sz++;
                temp = temp->next;
            }
        }

        void print() {
            if ( head == NULL )
                return;

            node *temp = head;
            while ( temp != NULL ) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    sl_list *sll = new sl_list();
    for (int i = 0; i < n; i++) {
        int d;
        cin>>d;
        sll->append(d);
    }

    sll->print();
    
    int key;
    cin>>key;

    sll->remove(key);
    sll->print();
}
