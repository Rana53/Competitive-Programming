#include<stdio.h>
#include<stdlib.h>
struct Node {
    int value;
    struct Node *next;
};
struct Node * rootNode;

void printList(){
    struct Node *prtNext;
    if(rootNode == NULL){
        printf("No List Created\n");
        return;
    }
    printf("List contain:");
    prtNext = rootNode;
    while(prtNext->next != NULL){
        printf("    %d",prtNext->value);
        prtNext = prtNext->next;
    }
    printf("    %d\n",prtNext->value);
}

void createNode(int n){
    struct Node *newNode, *nextPtr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = n;
    newNode->next = NULL;
    if(rootNode == NULL){
        rootNode = newNode;
        return;
    }
    nextPtr = rootNode;
    while(nextPtr->next != NULL)
        nextPtr = nextPtr->next;
    nextPtr->next = newNode;
}
void insertIntoBegin(int n){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = n;
    newNode->next = rootNode;
    rootNode = newNode;
}
void insertIntoEnd(int n){
    struct Node *newNode, *ptrNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    ptrNode = (struct Node *)malloc(sizeof(struct Node));
    ptrNode = rootNode;
    newNode->value = n;
    newNode->next = NULL;
    while(ptrNode->next != NULL)
        ptrNode = ptrNode->next;
    ptrNode->next = newNode;
}
void insertIntoAfter(int n, int a){
    struct Node *newNode, *prevPtr, *nextPtr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = a;
    prevPtr = rootNode;
    while(prevPtr->value != n && prevPtr->next != NULL){
        prevPtr = prevPtr->next;
    }
    if(prevPtr->value != n){
        printf("no item %d found!!, insertion can't occure\n",n);
        return;
    }
    if(prevPtr->next == NULL){ // that's means leaf node
        insertIntoEnd(a);
        return;
    }
    nextPtr = prevPtr->next;
    prevPtr->next = newNode;
    newNode->next = nextPtr;
}

int main(){
    createNode(4);
    createNode(2);
    createNode(5);

    insertIntoBegin(-50);
    insertIntoEnd(50);
    insertIntoAfter(50,0);
    insertIntoAfter(5,-5);
    insertIntoAfter(10,-1000);
    //printf("root node value = %d\n",rootNode->value);
    printList();
    return 0;
}
