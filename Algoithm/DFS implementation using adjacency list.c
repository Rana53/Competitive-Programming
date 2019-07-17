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
    if(graph[u]->head==NULL){
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

}
void BFS(int n){
    int stack[MAX], top , u, v;
    top = 0;
    stack[top++] = n;
    visited[n] = 1;
    while(top>0){
        u = stack[--top];
        Node *node;
        printf(" %d ", u);
        node = graph[u]->head;
        if(node != NULL){
            while(node->next!=NULL){
                v = node->vertex;
                if(!visited[v]){
                    stack[top++] = v;
                    visited[v] = 1;
                }
                node = node->next;
            }
            v = node->vertex;
            if(!visited[v]){
                stack[top++] = v;
                visited[v] = 1;
            }
        }
    }

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
   BFS(1);
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
