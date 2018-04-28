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

        node *last_node() {
            node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            return temp;
        }

        void pairsum(int sum) {
            node *first = head;
            node *second = last_node();
            bool pair_found = false;
            while (first != NULL && second != NULL && first != second->next && first != second) {
                if ((first->data + second->data) == sum) {
                    pair_found = true; 
                    cout << first->data << " " << second->data;
                    first = first->next;
                    second = second->prev;
                }
                else {
                    if ((first->data + second->data) < sum)
                        first = first->next;
                    else 
                        second = second->prev;
                }
            }
            if (pair_found == false)
                cout << "not found";
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
    for (int i = 0; i < n; i++) {
        int t; 
        cin>>t;
        l->append(t);
    }
    l->print();
    
    int sum;
    cin>>sum;
    l->pairsum(sum);
}
