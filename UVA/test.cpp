#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
char grid[201][201];
int n;
int fx[] = {-1,-1, 0, 0,+1,+1};
int fy[] = {-1, 0,-1,+1, 0,+1};

struct Point{
    int row;
    int col;
};

bool valid(Point point){
    if(point.col < 0 ||  n <= point.col) return false;
    if(point.row < 0 ||  n <= point.row) return false;
    return true;
}

bool BFS(Point point){
    int visited[n][n];
    memset(visited,0,sizeof(visited));
    Point Q[40000],qPoint, newPoint;
    int qPos, qsize;
    qPos = 0;
    qsize = 1;
    Q[qPos] = point;
    visited[point.row][point.col] = 1;
    while(qPos < qsize){
        qPoint = Q[qPos++];
        for(int i = 0; i < 6; i++){
            newPoint.row = qPoint.row + fx[i];
            newPoint.col = qPoint.col + fy[i];
            if(valid(newPoint) && grid[newPoint.row][newPoint.col] == 'b' && visited[newPoint.row][newPoint.col] == 0)
            {
                 Q[qsize++] = newPoint;
                 visited[newPoint.row][newPoint.col] = 1;
                 if(newPoint.row + 1 == n || newPoint.col + 1 == n)
                     return true;
            }
        }
    }
    return false;
}

int main(){
    Point point;
    bool blackWin = false;
    int count = 1;
    while(cin>>n,n){
        for(int i = 0; i < n; i++)
            scanf("%s",grid[i]);

        for(int i = 0; i < n; i++){
            if(grid[0][i] == 'b'){
                point.row = 0, point.col = i;
                blackWin = BFS(point);
                if(blackWin) break;
            }
        }
        cout << count <<" " << (blackWin == true ? "B" : "W") << endl;
        count++;
    }
    return 0;
}

/*
4
bbwb
wwbw
bwwb
wwbb

*/
