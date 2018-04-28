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

        void split(node **h1, node **h2) {
            node *fast = head, *slow = head;
            while (fast->next != head && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            if (fast->next->next == head)
                fast = fast->next;

            *h1 = head;
            if (head->next != head)
                *h2 = slow->next; 
            fast->next = slow->next; 
            slow->next = head;
        }

        void print() {
            node *temp = head;
            if (head == NULL) {
                cout << "empty here";
                return;
            }
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
        cll->append(t);
    }
    cll->print();

    cl_list *c1 = new cl_list;
    cl_list *c2 = new cl_list;
    cll->split(&c1->head, &c2->head);
    c1->print();
    c2->print();
}
