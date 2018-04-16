#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *next;
        node() {}
        node(int d): data(d), next(NULL) {}
        node(int d, node *n): data(d) {
            //next = new node;
            next = (n != NULL) ? n : NULL;
        }
};

class cl_list {
    public:
        node *head;

        cl_list() {}

        void append(int key) {
            node *newnode = new node(key);
            if (head == NULL) {
                newnode->next = newnode;
                head = newnode;
                return;
            }

            node *temp = head;
            while (temp->next != head) 
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }

        void print() {
            node *temp = head;
            if (head == NULL)
                return;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
        }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    cl_list *cll = new cl_list;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        cll->append(t);
    }
    cll->print();
}
