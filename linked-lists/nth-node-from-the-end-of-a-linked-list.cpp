#include <iostream>

using namespace std;

class node {
    public:
        int data;
        node *next;

        node() {}

        node(int d): data(d), next(NULL) {}
        
        node(int d, node *n): data(d) {
            next = (n != NULL) ? n : NULL;
        }
};

class sl_list {
    public:
        node *head;

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

        int last_nth(int n) {
            int count = 0;
            node *ahead = head, *curr = head;
            while (ahead != NULL && count < n) {
                count++;
                ahead = ahead->next;
            }

            while (ahead != NULL) {
                curr = curr->next;
                ahead = ahead->next;
            }

            return curr->data;
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

    int key;
    cin>>key;

    cout << sll->last_nth(key);
}
