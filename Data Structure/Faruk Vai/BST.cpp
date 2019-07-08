#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    node *left;
    node *right;
};


struct node* root;

struct node* insert(struct node* r, int data);

int main()
{
    root = NULL;
    int n, v;

    printf("How many data's do you want to insert ?\n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Data %d: ", i+1);
        scanf("%d", &v);
        root = insert(root, v);
    }
    return 0;
}

struct node* insert(struct node* r, int data)
{
    if(r==NULL)
    {
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if(data < r->value){
        r->left = insert(r->left, data);
    }
    else {
        r->right = insert(r->right, data);
    }
    return r;

}
