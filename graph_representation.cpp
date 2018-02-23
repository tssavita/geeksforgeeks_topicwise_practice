#include <list>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class adjListNode {
    int data;
    adjListNode *next; 
    
    public:
    
    adjListNode() {}
    
    adjListNode(int node_data): data(node_data), next(NULL) {}
    
    adjListNode(int node_data, adjListNode *node_next): data(node_data), next(node_next) {}
    
    int getData() { 
        return data;
    }
    
    void setData(int node_data) {
        data = node_data;
    }
    
    adjListNode *getNextNode() {
        return next;
    }

    void setNextNode(adjListNode *next_node) { 
        next = next_node;
    }
};

class adjList {
    adjListNode *head;
    
    public:
    
    adjList(): head(NULL) {}

    bool isHeadNULL() {
        if ( head != NULL )
            return false;
        return true;
    }

    void setHead(adjListNode *head_node) {
        head = head_node;
    }
    
    adjListNode *getHead() {
        if (head != NULL)
            return head;
        return NULL;
//        return (isHeadNULL() == true)? NULL : head;
    }
};

class Graph {
    public:
    
    int vertices;
    adjList *array;
    
    Graph() {}

    Graph(int vertex_number): vertices(vertex_number) {
        array = new adjList[vertex_number];
        for (int i = 0; i < vertices; i++) {
            array[i].setHead(NULL);
        }
    }

    void addEdge(int src, int dest) {
        cout << "Adding edge between " << src << " and " << dest << ".";
        adjListNode *new_node = new adjListNode(dest);
        adjListNode *new_head = array[src].getHead();
        new_node->setNextNode(new_head);
        new_node->setData(new_head->getData());
        array[src].setHead(new_node);
        
        new_node->setData(src);
        new_head = array[dest].getHead();
        new_node->setNextNode(new_head);
        array[dest].setHead(new_node);
    }

    void print() {
        cout << "Printing graph";
        for (int i = 0; i < vertices; i++) {
            adjListNode *pCrawl = array[i].getHead();
            cout << i << "-";
            while ( !pCrawl ) {
                cout << pCrawl->getData()<< " ";
                pCrawl = pCrawl->getNextNode();
            }
            cout << endl; 
        }
    }
};

int main(int argc, char **argv) {
    
    int num_vertex;
    cin>>num_vertex;
    Graph *g = new Graph(num_vertex);
    
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(0, 3);

    g->print();
}
