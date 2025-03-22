#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* createNode(void*value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value=value;
        newNode->next = NULL;
    }
    return newNode;
}

void insert(List* someList, void* value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    if (someList->head == NULL) {
        someList->head = newNode;
    } else {
        Node* myNode = someList->head;
        while (myNode->next != NULL) {
            myNode = myNode->next;
        }
        myNode->next = newNode;
    }
}


void* removeNode(List* list) {

 void* value;
 
    Node* prevNode = NULL;
    Node* currNode = list->head;
    while (currNode->next != NULL) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    value = currNode->value;
    if (prevNode != NULL) {
        prevNode->next = NULL;
    } else {
        list->head = NULL;
    }
    free(currNode);
    return value;
}

List* generateList(){
    List* list;
    list = (List*)malloc(sizeof(List));
    (*list).head = NULL;
    return list;
}

void freeNode(Node* node) {
    free(node->value);
    free(node);      
}


void freeList(List* list) {
    Node* current = list->head;
    Node* temp;

    
    while (current != NULL) {
        temp = current;
        current = current->next;
        freeNode(temp); 
    }

    
    free(list);
}


