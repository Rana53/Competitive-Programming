#include<stdio.h>
#include<stdlib.h>
#define MaxNode 100001
typedef struct Node{
    int vertex;
    struct Node *next;
}Node;

typedef struct Graph{
    Node *head;
}Graph;
// Global data type
Graph *graph[MaxNode] = {0};
int level


void graphInitialize(){
    int i;
    for(i = 0; i < MaxNode; i++){
        graph[i] = (Graph *)malloc(sizeof(Graph));
        graph[i]->head = NULL;
    }
}
void addNode(int u, int v){
    printf("Work   u = %d v = %d\n",u,v);
    Node *newNode, *ptr;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;

    if(graph[u]->head == NULL)
        graph[u]->head = newNode;
    else{
        ptr = graph[u]->head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}
void printList(int n){
    int i;
    Node *node;
    for(i = 1; i < n ; i++){
        printf("%d",i);
        for(node = graph[i]->head; node->next!=NULL; node = node->next){
            printf(" %d",node->vertex);
        }
        printf(" %d",node->vertex);
        printf("\n");
    }
}

int main(){
    int n, i, u, v;
    scanf("%d", &n);
    graphInitialize();
    for(i = 1; i < n; i++){
        scanf("%d %d",&u, &v);
        addNode(u,v);
        addNode(v,u);
    }
    scanf("%d",&l);
   // printList(n);
    return 0;
}
