#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{int   data; struct Node* next;}Node;
typedef struct LinkedList  {Node* head; unsigned int size;}LL;

Node* createNode(int);
LL* createLL(int);
LL* createFromArrLL(int*, size_t);
void toStringLL(LL*);
void freeNode(Node*);
void freeLL(LL*);

int main(int argc, char**argv){

    LL* list0 = createLL(5);
    int randArr[5] = {1,2,3,4,5};
    LL* list1 = createFromArrLL(randArr, sizeof(randArr)/sizeof(*randArr));

    toStringLL(list0);
    toStringLL(list1);

    freeLL(list0);
    freeLL(list1);

    return 0;
}
void search(LL* list, int data){
    if(list == NULL)
        return NULL;
    Node* curr = list->head;
    while (curr != NULL){
        if(curr->data==data)
            return curr;
        curr=curr->next;
    }
    return NULL;
}
void append(LL* list, int data){
    if(list == NULL)
        return NULL;
    Node* curr = list->head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next = createNode(data);
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
void toStringLL(LL* list) {

    if(list==NULL)
        return NULL;

    Node*curr=list->head;
    while (curr!=NULL){
        printf("%d\n", curr->data);
        curr=curr->next;
    }
}
void freeLL(LL* list){
    if(list==NULL)
        return NULL;

    freeNode(list->head);
    free(list);
}
void freeNode(Node* node){
    if(node==NULL)
        return NULL;

    if (node != NULL) {
        freeNode(node->next);
        free(node); // Free each node in the linked list
    }
}