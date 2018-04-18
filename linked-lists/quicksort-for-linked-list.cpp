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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

class dll {
    public: 
        node *head;
        
        dll() {}

        void prepend(int key) {
            node *temp = new node(key, NULL, head);
            if (head != NULL) 
                head->prev = temp; 
            head = temp;
        }

        node *last_node() {
            if (head == NULL)
                return NULL;

            node *temp = head;
            while(temp->next != NULL) 
                temp = temp->next;

            return temp;
        }

        node *partition(node *low, node *high) {
            node *i = low->prev;
            int x = high->data;
            for (node *j = low; j != high && j != NULL; j = j->next) {
                if (j->data <= x) {
                    i = (i == NULL) ? low : i->next;
                    swap(&(i->data), &(j->data));
                }
            }
            i = (i == NULL) ? low : i->next;
            swap(&(i->data), &(high->data));

            return i;
        }

        void *quicksort_util(node *low, node *high) {

            if (low != NULL && high != NULL && low != high->next) {
                node *q = partition(low, high);
                quicksort_util(low, q->prev);
                quicksort_util(q->next, high);
            }
        }

        void *quicksort() {
            node *tail = last_node();
            if (tail != NULL)
                quicksort_util(head, tail);
        }

        void print() {
            node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};


void print(node *n) {
    node *temp = n;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    dll *d = new dll;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        d->prepend(t);
    }

    d->print();

    d->quicksort();
    d->print();
}
