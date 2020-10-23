#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct node {
    int value;               
    struct node* next;   
} Node;

Node* create();

void addOnBegin(Node* head, int value);

void addOnEnd(Node* head, int value);

int removeLastOne(Node* head);

void printNodeList(Node* head);

int removeValue(Node* head, int value);

void addOrdenered(Node* head, int value);

#endif