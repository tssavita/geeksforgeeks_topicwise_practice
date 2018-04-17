#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node *prev;
        node *next;
        node() {}
        node(int d): data(d), prev(NULL), next(NULL) {
        }
        node(int d, node *p, node *n): data(d) {
            next = new node;
            next = (n != NULL) ? n : NULL;
            prev = new node; 
            prev = (p != NULL) ? p : NULL;
        }
};

class dl_list {
    public: 
        node *head;

        dl_list() {}

        void before_head(int key) {
            node *newnode = new node(key, NULL, head);
            if (head != NULL)
                head->prev = newnode;
            head = newnode; 
        }

        void after_node(node *prev_node, int key) {
            node *newnode = new node(key, prev_node, NULL);
            if (prev_node->next != NULL) {
                newnode->next = prev_node->next;
                newnode->next->prev = newnode; 
            }
            prev_node->next = newnode;
        }

        void before_node(node *after_node, int key) {
            node *newnode = new node(key, NULL, after_node);
            if (after_node->prev != NULL) {
                newnode->prev = after_node->prev;
                newnode->prev->next = newnode;
            }
            after_node->prev = newnode;
        }

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

    dl_list *dll = new dl_list;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        dll->before_head(t);
        dll->append(10);
        dll->after_node(dll->head, 8);
    }
    dll->print();
}
