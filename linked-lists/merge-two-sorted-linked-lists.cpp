#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;
        node() {}
        node(int d): data(d), next(NULL) {}
        node(int d, node *n): data(d) {
            next = new node;
            next = (n != NULL) ? n : NULL;
        }
};

class sl_list {
    public:
        node *head;

        sl_list() {}

        void append(int key) {
            if (head == NULL) {
                head = new node(key);
                return;
            }

            node *temp = head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = new node(key);
        }

        void print() {
            node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

void move_node(node *src, node *dest) {
    node *temp = src; 
    src = temp->next; 
    temp->next = dest;
    dest = temp;
}   

node *merge(node *a, node *b) {
    node dummy;
    node *tail = &dummy; 
    while (1) {
        if (a == NULL) {
            tail->next = b;
            break;
        }
        if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->data <= b->data) 
            move_node(a, tail->next);
        else 
            move_node(b, tail->next);
        tail = tail->next;
    }

    return dummy.next;
}

int main(int argc, char ** argv) {
    int na, nb;
    cin>>na>>nb;

    sl_list *a = new sl_list;
    for (int i = 0; i < na; i++) {
        int t;
        cin>>t;
        a->append(t);
    }

    sl_list *b = new sl_list;
    for (int i = 0; i < nb; i++) {
        int t;
        cin>>t;
        b->append(t);
    }

    a->print();
    b->print();

    node *hm = merge(a->head, b->head);
    sl_list *m = new sl_list;
    m->head = (node *)hm;
    m->print();
}
