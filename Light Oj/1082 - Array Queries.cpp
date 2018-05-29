#include<bits/stdc++.h>
#define getint(x) scanf("%d",&x);
#define mx 1000009
 
using namespace std;
 
int ara[mx];
int tree[4*mx];
 
void treeInit(int node, int s, int e){
    if(s == e){
        tree[node] = ara[s];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = ( s + e ) / 2;
    treeInit(left, s, mid);
    treeInit(right, mid + 1, e);
    tree[node] = tree[left] < tree[right] ? tree[left] : tree[right];
}
 
int getMin(int node,int s, int e, int i, int j){
    if(i > e || j < s)
        return 1000000000;
 
    if(s >= i && e <= j)
        return tree[node];
 
    int left = node * 2;
    int right = left + 1;
    int mid = ( s + e ) / 2;
    int p = getMin(left, s, mid, i, j);
    int q = getMin(right, mid + 1, e, i, j);
    return p < q ? p : q;
}
 
int main(){
    int t, tc = 1, n, q, i, j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int l = 0; l < n; l++)
            scanf("%d",&ara[l]);
        treeInit(1, 0, n-1);
        printf("Case %d:\n",tc++);
        while(q--){
            scanf("%d %d",&i,&j);
            printf("%d\n",getMin(1,0,n-1,i-1,j-1));
        }
    }
    return 0;
}