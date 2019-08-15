#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
char grid[100][100];
char line[10];
int a , b;
int fx[] = {-1,+1, 0, 0 ,-1, +1, -1, +1};
int fy[] = {0 , 0,+1,-1, -1, +1, +1, -1};
int sz;

struct Point{
   int r, c;
};
void getIJInAB(){
    int len, mul,i;
    a = 0;
    b = 0;
    mul = 1;
    len = strlen(line);
    for(i = len - 1; line[i] != ' '; i--){
        b += mul *(line[i] - '0');
        mul *= 10;
    }
    for(i--,mul = 1; i>= 0; i--){
        a += mul *(line[i] - '0');
        mul *= 10;
    }
   // cout << "Print a b " << a << "  -- " << b << endl;
}

bool valid(Point point){
    if(point.r < 0 || point.c < 0)
        return false;
    if(point.r >= sz || point.c >= sz)
        return false;
    return true;
}

int BFS(Point point){
    int visited[sz][sz];
    memset(visited,0,sizeof(visited));
    Point Q[10000], newPoint, qPoint;
    int qPos, qLimit, count = 1;
    qPos = 0, qLimit = 1;
    Q[qPos] = point;
    visited[point.r][point.c] = 1;
    while(qPos < qLimit){
        qPoint = Q[qPos++];
        for(int i = 0; i < 8; i++){
           newPoint.r = qPoint.r + fx[i];
           newPoint.c = qPoint.c + fy[i];
           if(valid(newPoint) && !(visited[newPoint.r][newPoint.c])&& grid[newPoint.r][newPoint.c] == 'W'){
               cout <<"adj point " << newPoint.r << " - " << newPoint.c << endl;
               Q[qLimit++] = newPoint;
               visited[newPoint.r][newPoint.c] = 1;
               count++;
           }
        }
    }
    return count;
}

int main(){
    int t, len, n, ans;
    char enterCheck;
    Point point;
    cin >> t;
    cout << endl;
    while(t--){
        cin >> grid[0];
        n = strlen(grid[0]);
        sz = n;
        for(int i = 1; i < n; i++)
            cin >> grid[i];
        cin.get();
        while(scanf("%[^\n]",line)){
            cin.get();
            if(line[0]=='\n') break;
            getIJInAB();
            point.r = a - 1;
            point.c = b - 1;
            ans = BFS(point);
            cout << "Output - " << ans << endl;
        }
        if(t) cout << endl;
    }
    return 0;
}

