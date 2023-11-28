#include <stdio.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{int data; struct Node* next;}Node;
typedef struct LinkedList  {Node* head; unsigned int size;}LL;

/*Creation function(s)*/
LL* createLL(int);
LL* createFromArrLL(int*, size_t);
Node* createNode(int);

/*Destruction function(s)*/
void freeNode(Node*);
void freeLL(LL*);

/*Insertion function(s)*/
void insert(LL*, int, int);
void append(LL*, int);//enqueue
void insertAtHead(LL*, Node*); //push

/*Deletion function(s)*/
Node* removeFromTail(LL*);//dequeue
Node* removeFromHead(LL*); //pop

/*Util function(s)*/
int nodeExists(LL*, int); //returns 0 or 1 pending whether data is found or not
void toStringLL(LL*);

#endif