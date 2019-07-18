#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
typedef struct Node{
    int vertex;
    struct Node *next;

}Node;
typedef struct Graph{
    Node *head;

}Graph;

Graph *graph[MAX] = {0};
int visited[MAX];

void graphInitialize(){
    int i;
    for(i  = 0; i < MAX; i++){
        graph[i] = (Graph*)malloc(sizeof(Graph));
        graph[i]->head = NULL;
        visited[i] = 0;
    }
}

void addNode(int u, int v){
    Node *newNode, *ptr;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    if(graph[u]->head == NULL){
        graph[u]->head = newNode;
    }
    else{
        ptr = graph[u]->head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}
void printGraph(){
    printf("Adjacency list print:\n");
    int i;
    Node *ptr;
    for(i = 0;i < MAX; i++){
        printf("%d: ", i);
        if(graph[i]->head != NULL){
           ptr = graph[i]->head;
           while(ptr->next != NULL){
               printf(" %d", ptr->vertex);
               ptr = ptr->next;
           }
           printf(" -%d",ptr->vertex);
        }
        printf("\n");
    }
    printf("End of printGraph function\n");
}
void DFS(int n){
    printf("%d\n",n);
    visited[n] = 1;
    Node *node;
    node = graph[n]->head;
    if(node != NULL){
        while(node->next != NULL){
            if(!visited[node->vertex])
                DFS(node->vertex);
            node = node->next;
        }
        if(!visited[node->vertex])
            DFS(node->vertex);
    }

    return;
}

int main(){
    int n, e, i, u, v;
    graphInitialize();
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d %d",&u,&v);
        addNode(u,v);
    }
    printGraph();
    DFS(1);
    return 0;
}
/*
Input:
4
1 2
1 3
2 4
2 5
*/
