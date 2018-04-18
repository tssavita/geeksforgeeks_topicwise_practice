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
        
        void sortninsert(int key) {
            node *newnode = new node(key);
            if (head == NULL) {
                newnode->next = newnode;
                head = newnode;
            }
            else if (key <= head->data) {
                node *temp = head;
                while (temp->next != head) 
                    temp = temp->next;
                temp->next = newnode;
                newnode->next = head; 
                head = newnode; 
            }
            else {
                node *temp1 = head;
                while (temp1->next != head && temp1->next->data < newnode->data) 
                    temp1 = temp1->next; 

                newnode->next = temp1->next;
                temp1->next = newnode;
            }
        }

        void print() {
            node *temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next; 
            } while (temp != head);
            cout << endl;
        }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    cl_list *cll = new cl_list; 
    for (int i = 0; i < n; i++) {
        int t; 
        cin>>t;
        //cll->append(t);
        cll->sortninsert(t);
    }
    cll->print();

//    cll->sortninsert(5);
    cll->print();
}
