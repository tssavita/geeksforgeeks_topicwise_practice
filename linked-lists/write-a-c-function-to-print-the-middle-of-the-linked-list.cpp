#include <iostream>
#include <climits>

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
            while(temp->next != NULL) 
                temp = temp->next;
            temp->next = new node(key);
        }

        int size() {
            node *temp = head;
            int sz = 0;
            while(temp != NULL) {
                temp = temp->next;
                sz++;
            }

            return sz;
        }

        int mid() {
            int n = size() / 2;
            if (n == 0)
                return INT_MIN;
            
            node *temp = head;
            while (temp != NULL) {
                if (n == 0)
                    return temp->data;
                temp = temp->next;
                n--;
            }
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

    sl_list *sll = new sl_list();
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        sll->append(t);
    }
    sll->print();
    cout << sll->mid();
}
