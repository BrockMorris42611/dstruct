#include "LinkedList.h"
#include <stdlib.h>
int oringalTests();
int main(){
    LL* list = createLL(5);
    insertAtHead(list,createNode(6));
    toStringLL(list);

    return EXIT_SUCCESS;
}

int oringalTests(){
    //                0 1 2 3 4
    int randArr[5] = {1,2,3,4,5};
    LL* list = createFromArrLL(randArr, sizeof(randArr)/sizeof(*randArr));
    printf("init size of list: %d\n", list->size);
    toStringLL(list);
    append(list, 6);
    toStringLL(list);
    int valueToFind = 99;
    if(nodeExists(list, valueToFind))
        printf("\nnode with data value %d exists!\n", valueToFind);
    else
        printf("\nnode with data value %d doesnt exist!\n", valueToFind);
    insert(list, 3, 99);
    toStringLL(list);
    insertAtHead(list, createNode(11));
    toStringLL(list);
    Node* node = removeFromHead(list);
    printf("\nRemoved head value: %d", node->data);
    freeNode(node);
    Node* node0 = removeFromTail(list);
    printf("\nRemoved tail value: %d", node0->data);
    toStringLL(list);
    //freeNode(node0);
    freeLL(list);

    return 0;
}