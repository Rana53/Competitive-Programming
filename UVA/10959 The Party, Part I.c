#include<stdio.h>
#include<stdlib.h>
#define maxPerson 1000

typedef struct Node{
    int vertex;
    struct Node *next;

}Node;
typedef struct Graph{
    Node *head;
}Graph;
Graph *graph[maxPerson] = {0};
void graphInitialze(){
    int i;
    for(i = 0; i < maxPerson; i++){
        graph[i] = (Graph *)malloc(sizeof(Graph));
        graph[i]->head = NULL;
    }
}
void addNode(int u, int v){
  //  printf("Work   u = %d v = %d\n",u,v);
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
int main(){
     int t, p, d, i , u , v;
     scanf("%d",&t);
     while(t--){
         puts("");
         graphInitialze();
         scanf("%d %d",&p,&d);
         for(i = 0; i < d; i++){
             scanf("%d %d",&u,&v);
             addNode(u, v);
         }

     }

    return 0;
}
