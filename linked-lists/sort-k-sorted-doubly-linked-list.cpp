#include <iostream>
#include <queue>

using namespace std; 

class node {
    public:
        int data;
        node *prev;
        node *next;
        node() {}
        node(int d): data(d), prev(NULL), next(NULL) {}
        node(int d, node *p, node *n): data(d) {
            prev = new node;
            prev = p;
            next = new node;
            next = n;
        }
};

struct compare {
    bool operator() (node *n1, node *n2) {
        return (n1->data < n2->data);   
    }
};

class dl_list { 
    public:
        node *head;

        dl_list() {}

        void prepend(int key) {
            node *newnode = new node(key, NULL,  head);
            if (head != NULL)
                head->prev = newnode;
            head = newnode;
        }

        node *sort_k(int k) {
            if (head == NULL)
                return NULL;

            priority_queue<node *, vector<node *>, compare> pq;

            node *temp = head;
            for (int i = 0; i <= k; i++) {
                pq.push(temp);
                temp = temp->next;
            }

            node *h = NULL, *l;
            while ( !pq.empty() ) {
                if (h == NULL) {
                    h = pq.top();
                    h->prev = NULL;
                    l = h;
                }
                else {
                    l->next = pq.top();
                    pq.top()->prev = l;
                    l = pq.top();
                }

                pq.pop();

                if (temp != NULL) {
                    pq.push(temp);
                    temp = temp->next; 
                }
            }

            l->next = NULL;
            
            return h;
        }

        void print() {
            node *temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int main(int argc, char **argv) {
    int n;
    cin>>n;

    dl_list *d = new dl_list;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        d->prepend(t); 
    }
    d->print();
    node *s = d->sort_k(4);
    dl_list *sdl = new dl_list;
    sdl->head = s;
    sdl->print();
}
