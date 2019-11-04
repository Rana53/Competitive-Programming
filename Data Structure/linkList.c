#include<stdio.h>
#include<stdlib.h>
struct Node{
    int value;
    struct Node *next;
};

struct Node *rootNode;

void createNode(int n){
    struct Node *newNode, *nextPtr;
    newNode = (Node *)malloc(sizeof(Node));
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
void printList(){
    struct Node *prtNext;
    if(rootNode == NULL){
        printf("No List Created\n");
        return;
    }
    prtNext = rootNode;
    printf("List contain Value:");
    while(prtNext->next != NULL){
        printf("    %d",prtNext->value);
        prtNext = prtNext->next;
    }
    printf("    %d\n",prtNext->value);
}
int main(){
    createNode(5);
    createNode(10);
    printList();
    return 0;
}