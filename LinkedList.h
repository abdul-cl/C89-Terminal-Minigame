#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node {
    void* value; 
    struct Node* next;
} Node;

typedef struct List{
    struct Node* head;
}List;
Node* createNode(void*value); 

Node* createNode(void*value);
void insert(List*someList,void*value);
void* removeNode(List* someList);
List* generateList();
void freeNode(Node* node);
void freeList(List* list);


#endif
