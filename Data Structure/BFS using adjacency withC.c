#include<stdio.h>
#include<stdlib.h>
#define MaxNode 100

typedef struct Node{
    int vertex;
    struct Node *next;
}Node;

typedef struct Graph{
    struct Node *head;
}Graph;

//decleared data here

Graph *graph[MaxNode] = {0};

void makeGraph(){
    int i ;
    for( i = 0; i < MaxNode; i++){
        graph[i] = (Graph *)malloc(sizeof(Graph));
        graph[i]->head = NULL;
    }
    printf("graph initialize done\n");
}
void addNode(int u, int v){
    Node *sourceNode, *desNode, *ptrNode;
    if(graph[u]->head == NULL){
        sourceNode = (Node *)malloc(sizeof(Node));
        sourceNode->vertex = u;
        sourceNode->next = NULL;
        graph[u]->head = sourceNode;
    }

    desNode = (Node *)malloc(sizeof(Node));
    desNode->vertex = v;
    desNode->next = NULL;

    ptrNode = graph[u]->head;
    while(ptrNode->next !=NULL)
        ptrNode= ptrNode->next;

    ptrNode->next = desNode;
}
void printList(int n){
    int i;
    Node *node;
    for(i = 0; i < n; i++){
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
    makeGraph();
    scanf("%d",&n); // here n is number of edge
    for(i = 0; i < n - 1; i++){
        scanf("%d %d",&u, &v);
        addNode(u,v);
        addNode(v,u);
    }
    printList(n);
    return 0;
}

/*
8
0 1
0 2
0 3
1 4
1 5
2 6
2 7
3 7

*/






