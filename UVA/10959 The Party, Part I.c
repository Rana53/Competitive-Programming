#include<stdio.h>
#include<stdlib.h>
#define maxPerson 1000

typedef struct Node{
    int vertex;
    Node *next;

}Node;
typedef Graph{
    Node *next;
};
Graph *graph[maxPerson] = {0};
void graphInitialze(){
    int i;
    for(i = 0; i < maxPerson; i++){
        graph[i] = (Graph *)malloc(sizeof(Graph));
        graph[i]->head = NULL;
    }
}

int main(){
     int t, p, d;
     scanf("%d",&t);
     while(t--){
         puts();

     }

    return 0;
}
