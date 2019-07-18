//Same code accepted by C++ but compiler error in C
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define maxPerson 1000
typedef struct Node{
    int vertex;
    struct Node *next;

}Node;
typedef struct Graph{
    Node *head;
}Graph;

struct Graph *graph[maxPerson] = {0};
int personLevel[1000];
int visited[1000];

void graphInitialze(int n){
    int i;
    for(i = 0; i < n; i++){
        graph[i] = (Graph *)malloc(sizeof(Graph));
        graph[i]->head = NULL;
        personLevel[i] = 0;
        visited[i] = 0;
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
void BFS(void){
    int queue[1000], qPos, qLimit, u, v;
    qPos = 0;
    queue[qPos] = 0;
    qLimit = 1;
    visited[0] = 1;
    personLevel[1] = 1;
    while(qPos < qLimit){
        u = queue[qPos++];
        Node * node = graph[u]->head;
        if(node != NULL){
            for( ; node->next != NULL; node = node->next){
                v = node->vertex;
                if(!visited[v]){
                    queue[qLimit++] = v;
                    visited[v] = 1;
                    personLevel[v] = personLevel[u] + 1;
                }
            }
            v = node->vertex;
            if(!visited[v]){
                queue[qLimit++] = v;
                visited[v] = 1;
                personLevel[v] = personLevel[u] + 1;
            }
        }

    }
}

int main(){
     int t, p, d, i , u , v;
     bool is = false;
     scanf("%d",&t);
     while(t--){
        // puts("");
         scanf("%d %d",&p,&d);
         graphInitialze(p);
         for(i = 0; i < d; i++){
             scanf("%d %d",&u,&v);
             addNode(u, v);
             addNode(v, u);
         }
         BFS();
         if(is)
             printf("\n");
         for(i = 1;i < p; i++)
             printf("%d\n",personLevel[i]);

         is = true;
     }

    return 0;
}
/*
2

5 6
0 1
0 2
3 2
2 4
4 3
1 2
*/
