#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    class node *left, *right;
    node(){
        left = NULL ;right = NULL;
        cout << "new node is created" << endl;
    }
    node(int v){
        left = NULL ;right = NULL;
        value = v;
    }
};
node *createNewNode(int value){
    return new node(value);
}
class node *insertIntoTree(class node * node, int value){
    class node *newNode;
    if(node == NULL)
        createNewNode(value);
}

int main(){
    class node *root = NULL;
    insertIntoTree(*root, 10);

    return 0;
}
