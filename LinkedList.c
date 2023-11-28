#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void insertAtHead(LL* list, Node* newHead){
    if(list == NULL)
        return;
    Node* temp = list->head;
    list->head=newHead;
    newHead->next = temp;
    list->size++;
}
Node* removeFromHead(LL* list){
    if(list==NULL)
        return NULL;
    Node* removedHead = list->head;
    list->head= list->head->next;
    list->size--;
    removedHead->next=NULL;
    return removedHead;
}
Node* removeFromTail(LL* list){ //not working
    Node* curr = list->head;
    Node*  prev = NULL;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    return curr;
}
void insert(LL* list, int ind, int data){
    Node* newNode = createNode(data);
    if(newNode==NULL || list==NULL)
        return;
    Node* curr = list->head;
    int counter = 0;
    while(curr!=NULL && counter < ind-1){
        curr=curr->next;
        counter++;
    }
    Node* temp = curr->next;
    curr->next = newNode;
    curr->next->next=temp;
    list->size++;
}
int nodeExists(LL* list, int data){
    if(list == NULL)
        return 0;
    Node* curr = list->head;
    while (curr != NULL){
        if(curr->data==data)
            return 1;
        curr=curr->next;
    }
    return 0;
}
void append(LL* list, int data){
    if(list == NULL)
        return;
    Node* curr = list->head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next = createNode(data);
    list->size++;
}
LL* createLL(int data){
    LL* newList = malloc(sizeof(LL));
    if (newList==NULL)
        return NULL;
    
    newList->head = createNode(data);
    newList->size = 1;
    return newList;
}
LL* createFromArrLL(int*dataArr, size_t dataArrSize){
    LL* newList = malloc(sizeof(LL));

    if(dataArr==NULL || newList==NULL)
        return NULL;

    newList->head = createNode(*dataArr);
    Node*curr = newList->head;

    for(size_t i = 1; i < dataArrSize; i++){
        curr->next=createNode(*(dataArr+i));
        curr=curr->next;
    }
    newList->size=dataArrSize;
    return newList;
}
Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    if (newNode== NULL)
        return NULL;
    
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void toStringLL(LL* list){
    if(list==NULL)return;
    Node*curr=list->head;
    int index = 0;
    printf("\n\t*******List of size %d*******\n", list->size);
    while (curr!=NULL){
        printf("list[%d]>\t%d\n", index, curr->data);
        curr=curr->next;
        index++;
    }
}
void freeLL(LL* list){
    if(list==NULL)return;
    freeNode(list->head);
    free(list);
}
void freeNode(Node* node){
    if(node==NULL)return;
    if (node != NULL) {
        freeNode(node->next);
        free(node); // Free each node in the linked list
    }
}