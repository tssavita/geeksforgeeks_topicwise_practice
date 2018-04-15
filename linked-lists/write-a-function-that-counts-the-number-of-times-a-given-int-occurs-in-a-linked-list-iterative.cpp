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

        int count(int key) {
            node *temp = head;
            int count = 0;
            while (temp != NULL) {
                if (temp->data == key)
                    count++;
                temp = temp->next; 
            }

            return count;
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

    sl_list *sll = new sl_list;
    for (int i = 0; i < n; i++) {
        int t; 
        cin>>t;
        sll->append(t);
    }

    sll->print();

    int key;
    cin>>key;
    cout << sll->count(key);
}
