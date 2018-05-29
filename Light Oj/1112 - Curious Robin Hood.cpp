#include<bits/stdc++.h>
 
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
 
#define mx 1000009
 
using namespace std;
int ara[mx];
int tree[4*mx];
 
void intTree(int node, int start, int end){
    if(start == end){
        tree[node] = ara[start];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (start + end) / 2;
    intTree(left, start, mid);
    intTree(right, mid + 1, end);
    tree[node] = tree[left] + tree[right];
}
 
void update(int node, int start, int end, int i,int newValue){
    if(i > end || i < start)
        return;
    if(start >= i &&  end <= i){
        tree[node] = newValue;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (start + end) / 2;
    update(left, start, mid, i, newValue);
    update(right, mid + 1, end, i, newValue);
    tree[node] = tree[left] + tree[right];
}
 
int query(int node, int start, int end, int i, int j){
    if(i> end || j < start)
        return 0;
    if(start >= i &&  end <= j)
        return tree[node];
    int left = node * 2;
    int right = left + 1;
    int mid = (start + end) / 2;
    int p = query(left, start, mid, i, j);
    int q = query(right, mid + 1, end, i, j);
    return p+q;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, t, nq, q, i, j , v, tc = 1;
    scanf("%d",&t);
    TEST_CASE(t){
        scanf("%d%d",&n,&nq);
        for(int k = 0; k < n; k++)
            scanf(" %d",&ara[k]);
        intTree(1, 0, n-1);
        printf("Case %d:\n",tc++);
        while(nq--){
            scanf("%d",&q);
            switch(q){
                case 1:
                    scanf("%d",&i);
                    printf("%d\n",ara[i]);
                    ara[i] = 0;
                    update(1, 0, n-1, i,ara[i]);
                    break;
                case 2:
                    scanf("%d%d",&i,&v);
                    ara[i] += v;
                    update(1, 0, n-1, i , ara[i]);
                    break;
                default:
                    scanf("%d%d",&i,&j);
                    printf("%d\n",query(1, 0, n-1, i , j));
                    break;
            }
        }
    }
    return 0;
}