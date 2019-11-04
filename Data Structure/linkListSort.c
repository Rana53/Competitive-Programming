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
    while(prtNext->next != NULL){
        printf("    %d",prtNext->value);
        prtNext = prtNext->next;
    }
    printf("    %d\n",prtNext->value);
}
void sortList(){
    struct Node *prevPtr, *nextPtr, *tmpPtr;
    if(rootNode == NULL){
        printf("No List Created\n");
        return;
    }
    prevPtr = rootNode;
    do{
        nextPtr = prevPtr;
        tmpPtr = nextPtr;
        while(nextPtr->next != NULL){
            if(tmpPtr->value > nextPtr->value)
                tmpPtr = nextPtr;
            nextPtr = nextPtr->next;
        }
        if(tmpPtr->value > nextPtr->value)
                tmpPtr = nextPtr;
            nextPtr = nextPtr->next;
        int tmpValue;
        tmpValue = prevPtr->value;
        prevPtr->value = tmpPtr->value;
        tmpPtr->value = tmpValue;

        prevPtr = prevPtr->next;

    }while(prevPtr->next != NULL);
}
int main(){
    int n, i, value;
    printf("Number of input : ");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d", &value);
        createNode(value);
    }
    printf("List contain before sorting: ");
    printList();
    sortList();
    printf("List contain after sorting: ");
    printList();
    
    return 0;
}