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
}

class dll {
    public: 
        node *head;

        dll() {}

        void prepend(int key) {
            node *newnode = new node(key, NULL, head);
            if (head != NULL)
                head->prev = newnode;
            head = newnode;
        }

        node *last_node() {
            node *temp = head;
            while(temp->next != NULL) 
                temp = temp->next;
            
            return temp;
        }

        node *part(node *first) {
            node *fast = first;
            node *slow = first;
            while (fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }

            node *temp = slow->next;
            slow->next = NULL;
            return temp;
        }

        node *merge(node *first, node *second) {
            if (first == NULL)
                return second; 
            if (second == NULL)
                return first;
            if (first->data < second->data) {
                first->next = merge(first->next, second);
                first->next->prev = first;
                first->prev = NULL;
                return first;
            }
            else {
                second->next = merge(first, second->next);
                second->next->prev = second; 
                second->prev = NULL;
                return second; 
            }
        }

        node *mergesort(node *first) {
            if (first == NULL || first->next == NULL)
                return first;

            node *second = part(first);

            first = mergesort(first);
            second = mergesort(second);

            return merge(first, second);
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

    dll *d = new dll;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        d->prepend(t);
    }
    d->print();

    d->mergesort(d->head);
    d->print();
}
