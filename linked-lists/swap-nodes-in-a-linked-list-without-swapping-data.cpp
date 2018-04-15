#include <iostream>

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
            while ( temp->next != NULL ) 
                temp = temp->next; 
            temp->next = new node(key);
        }

        void swap(int x, int y) {
            if (head == NULL)
                return;

            node *px, *py, *cx, *cy, *temp = head;
            while ( temp->next != NULL ) {
                if (temp->next->data == x) {
                    px = temp;
                    cx = temp->next;
                }

                if (temp->next->data == y) {
                    py = temp;
                    cy = temp->next;
                }

                temp = temp->next;
            }

            if ( px == NULL || py == NULL || cx == NULL || cy == NULL) 
                return;


            
            node *t = px->next;
            px->next = py->next;
            py->next = t;

            t = cx->next;
            cx->next = cy->next;
            cy->next = t;
            cout << px->data << " " << py->data << " " << t->data;
        }

        void print() {
            node *temp = head;
            while ( temp != NULL ) {
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

    int x, y;
    cin>>x>>y;
    sll->swap(x, y);

    sll->print();
}
