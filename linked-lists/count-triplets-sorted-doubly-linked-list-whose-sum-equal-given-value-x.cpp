#include <iostream>

using namespace std; 

class node {
    public:
        int data;
        node *next;
        node *prev;
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

        int triplets(int sum) {
            node *p1, *p2, *p3;
            int count = 0;
            for (p1 = head; p1 != NULL; p1 = p1->next) {
                for (p2 = p1->next; p2 != NULL; p2 = p2->next) {
                    for (p3 = p2->next; p3 != NULL; p3 = p3->next) {
                        if ((p1->data + p2->data + p3->data) == sum)
                            count++;
                    }
                }
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

    dl_list *dll = new dl_list;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        dll->prepend(t);
    }
    dll->print();
    
    int sum;
    cin>>sum;
    cout << dll->triplets(sum);
}
