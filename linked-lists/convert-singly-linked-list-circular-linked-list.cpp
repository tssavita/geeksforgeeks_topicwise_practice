#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *next;
        node() {}
        node(int d): data(d) {}
        node(int d, node *n): data(d) {
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
                head = newnode;
                return;
            }

            node *temp = head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newnode;
        }

        void convert_to_cll() {
            node *temp = head;
            if (head == NULL)
                return;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = head;
        }

        bool is_circular() {
            node *temp = head->next;
            while (temp != NULL && temp != head) 
                temp = temp->next;
            
            return (temp == head);
        }

        void print() {
            node *temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next; 
            } while (temp != NULL);
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
        cll->append(t);
    }

    cll->print();
    cll->convert_to_cll();
    cout << cll->is_circular();
}
