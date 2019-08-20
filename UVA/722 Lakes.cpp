#include<bits/stdc++.h>
char grid[105][105];
int visited[105][105];
int n;
int fx[] = {-1,+1,0,0};
int fy[] = {0,0,-1,+1};
int DFS(int i,int j){
    if(i<0 || i >= n) return 0;
    if(j<0 || j >= n) return 0;
    if(visited[i][j] || grid[i][j] !='0') return 0;
    visited[i][j] = 1;
    for(int k = 0; k < 4; k++)
        return 1 + DFS(i+fx[k],j+fy[k]);

}
using namespace std;
int main(){
    int t, a, b;
    char str[105];
    cin >> t;
    while(t--){
        gets(str);
        sscanf(str,"%d %d",&a,&b);
        cin >> grid[0];
        n = strlen(grid[0]);
        cout << n << grid[0] << endl;
        for(int i = 1; i < n; i++)
            cin >> grid[i];
        cout << DFS(a-1,b-1) << endl;
    }

    return 0;
}
/*
1

02 01
1001101
0011111
0001001
1100011
1111111
1100110
1110111
*/
