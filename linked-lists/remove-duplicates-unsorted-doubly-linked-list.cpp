#include <iostream>
#include <unordered_set>

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
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            delete temp;
        }

        void removedups() {
            if (head == NULL)
                return;
            unordered_set<int> s; 
            node *temp = head;
            while (temp != NULL) {
                if (s.find(temp->data) != s.end()) {
                    node *store_next = temp->next;
                    remove(temp);
                    temp = store_next;
                }
                else {
                    s.insert(temp->data);
                    temp = temp->next;
                }
            }
        }

        void print() {
            if (head == NULL)
                return;
            node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next; 
            }
            cout << endl;
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
    d->removedups();
    d->print();
}
