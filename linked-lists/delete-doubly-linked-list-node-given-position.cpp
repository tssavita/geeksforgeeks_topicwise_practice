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
            next = p;
        }
};

class dl_list {
    public:
        node *head;

        dl_list() {}

        void prepend(int key) {
            node *newnode = new node(key, NULL, head);
            if (head != NULL)
                head->prev = newnode;
            head = newnode;
        }

        void remove(node *temp) {
            if (head == NULL || temp == NULL)
                return;
            if (head == temp)
                head = temp->next;
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            delete temp;
        }

        void remove_at(int i) {
            if (head == NULL)
                return;
            node *temp = head;

            for (int j = 1; j < i && temp != NULL; j++) 
                temp = temp->next;

            if (temp == NULL)
                return;

            remove(temp);
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

    dl_list *d = new dl_list;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t; 
        d->prepend(t);
    }
    d->print();
    d->remove_at(3);
    d->print();
}
