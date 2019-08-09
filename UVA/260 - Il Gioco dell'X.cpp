#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
char grid[200][200];
int n;
int fx[] = {-1,-1, 0, 0,+1,+1};
int fy[] = {-1, 0,-1,+1, 0,+1};

struct Point{
    int row;
    int col;
}Point;

bool valid(Point point){
    if(point.col < 0 ||  n <= point.col) return false;
    if(point.row < 0 ||  n <= point.row) return false;
    return true;
}

bool DFS(Point point){
    int visited[n][n];
    memset(visited,0,sizeof(visited));
    Point queue[100],qPoint, newPoint;
    int qPos, qsize;
    qPos = 0;
    qsize = 1;
    queue[qPos] = point;
    while(qPos < qsize){
        qPoint = queue[qPos++];
        visited[qPoint.row][qPoint.col] = 1;
        for(int i = 0; i < 6; i++){
            newPoint.row = qPoint.row + fx[i];
            newPoint.col = qPoint.col + fy[i];
            if(valid(newPoint) &&
               grid[newPoint.row][newPoint.col] == 'b' &&
               visited[newPoint.row][newPoint.col] == 0)
            {
                 queue[qPos++] = newPoint;
                 qsize++;
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
            cin >> grid[i];

        for(int i = 0; i < n; i++){
            if(grid[0][i] == 'b'){
                point.row = 0, point.col = i;
                blackWin = DFS(point);
                if(blackWin) break;
            }
        }
        cout << count <<" " << endl;
        count++;
    }
    return 0;
}
