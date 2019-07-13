//Accepted
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
int level[MaxNode];
int visited[MaxNode];

// defined function here
void graphInitialize(){
    int i;
    for(i = 0; i < MaxNode; i++){
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

int BFS(int l){
    int queue[100001], qPos, qLimit, u, v, count = 0;
    qPos = 0;
    queue[qPos] = 1;
    qLimit = 1;
    visited[1] = 1;
    level[1] = 1;
    while(qPos < qLimit){
        u = queue[qPos++];
        if(level[u] == l) count ++;
        Node * node = graph[u]->head;
        if(node != NULL){
            for( ; node->next != NULL; node = node->next){
                v = node->vertex;
                if(!visited[v]){
                    queue[qLimit++] = v;
                    visited[v] = 1;
                    level[v] = level[u] + 1;
                }
            }
            v = node->vertex;
            if(!visited[v]){
                queue[qLimit++] = v;
                visited[v] = 1;
                level[v] = level[u] + 1;
            }
        }

    }
    return count;
}

//main function
int main(){
    int n, i, u, v, l;
    scanf("%d", &n);
    graphInitialize();
    for(i = 1; i < n; i++){
        scanf("%d %d",&u, &v);
        addNode(u,v);
        addNode(v,u);
    }
    scanf("%d",&l);
    printf("%d\n",BFS(l));
   // printList(n);
    return 0;
}
