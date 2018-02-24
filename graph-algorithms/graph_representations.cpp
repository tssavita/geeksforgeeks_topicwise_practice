#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class adjListNode {
    
    int data;

    adjListNode *next;
    
    public:

    adjListNode(int node_data): data(node_data), next(NULL) {}

    adjListNode(int node_data, adjListNode *node_next): data(node_data), next(node_next) {}

    int getData() {
        return data;
    }
    
    void setData(int node_data) {
        data = node_data;
    }

    adjListNode *getNext() {
        return next;
    }

    void setNext(adjListNode *next_node) {
        next = next_node; 
    }
};

class adjList {
    adjListNode *head;
    
    public: 
    
    adjList(): head(NULL) {}

    adjListNode *getHead() {
        return head;
    }

    void setHead(adjListNode *new_head) {
        new_head->setNext(head);
        head = new_head;
    }
};

class Graph {
    int vertices;
    adjList *array;

    public:

    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
        array = new adjList[vertices];
    }

    void addEdge(int src, int dest) {
        adjListNode *new_node = new adjListNode(dest);
//        new_node->setData(dest);
        array[src].setHead(new_node);

        new_node->setData(src);
//        new_node->setNext(NULL);
        array[dest].setHead(new_node);
    }

    void print() {
        for (int i = 0; i < vertices; i++) {
            adjListNode *pCrawl = array[i].getHead();
            cout << i << "-"; 
            while( pCrawl != NULL ) {
                cout << pCrawl->getData() << " ";
                pCrawl = pCrawl->getNext();
            }
            cout << endl;
        }
    }
};

int main(int argc, char ** argv) {
    int vertex_number;
    cin>>vertex_number;

    Graph *g = new Graph(vertex_number);

    g->addEdge(1, 0);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(3, 4);
    g->addEdge(4, 5);

    g->print();

}
