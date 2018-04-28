#include <iostream>

using namespace std;

int frequency = 0;

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

        void count(int key, node *temp) {
            if (head == NULL || temp == NULL)
                return;
            if (temp->data == key)
                frequency++;
            count(key, temp->next);
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
    sll->count(key, sll->head);
    cout << frequency;
}
