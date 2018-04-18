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

class l_list {
    public: 
        node *head;

        l_list() {}

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

        bool is_circular() {
            node *temp = head->next;
            if (head == NULL)
                return false;
            while (temp != NULL && temp != head)
                temp = temp->next;

            return (temp == head);
        }
};

int main(int argc, char ** argv) {
    int n;
    cin>>n;

    l_list *ll = new l_list;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        ll->append(t);
    }

    (ll->is_circular() == true) ? cout << "circular" : cout << "not circular";

    ll->head->next->next->next->next = ll->head;

    (ll->is_circular() == true) ? cout << "circular" : cout << "not circular";
}
