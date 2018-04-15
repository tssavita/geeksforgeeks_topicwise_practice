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
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = new node(key);
        }

        void prepend(int key) {
            node *temp = new node(key);
            temp->next = head;
            head = temp;
        }

        int nth_element(int key) {
            if (head == NULL)
                return INT_MIN;

            node *temp = head;
            while (temp != NULL) {
                if (key == 0)
                    return temp->data;
                temp = temp->next; 
                key--;
            }
            if (temp == NULL) 
                return INT_MIN;
        }

        void print() {
            if (head == NULL)
                return;
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

    int nth;
    cin>>nth;
    cout << sll->nth_element(nth-1); 
}
