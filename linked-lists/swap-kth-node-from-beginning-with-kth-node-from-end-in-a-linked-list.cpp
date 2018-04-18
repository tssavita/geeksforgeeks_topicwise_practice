#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *next;
        node() {}
        node(int d): data(d) {}
        node(int d, node *n): data(d) {
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
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new node(key);
        }

        int countnodes() {
            node *temp = head; 
            int sz = 0;
            while (temp != NULL) {
                sz++;
                temp = temp->next;
            }
            return sz;
        }

        void swap(int k) {
            int n = countnodes();
            if ( n < k)
                return;

            if (head == NULL)
                return;

            node *x = head, *x_prev = NULL;
            int i = 1;
            while (i < k) {
                x_prev = x;
                x = x->next;
                i++;
            }

            node *y = head, *y_prev = NULL;
            int j = 1;
            while ( j < (n - k + 1)) {
                y_prev = y;
                y = y->next;
                j++;
            }

            if (x_prev)
                x_prev->next = y;

            if (y_prev)
                y_prev->next = x;

            node *temp = x->next;
            x->next = y->next;
            y->next = temp;

            if (k == 1)
                head = y;
            if (k == n)
                head = x; 
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

    llist *l = new llist;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        l->append(t);
    }

    l->print();

    int k;
    cin>>k;

    l->swap(k);
    l->print();
}
