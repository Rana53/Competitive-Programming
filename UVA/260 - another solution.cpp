#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
char grid[201][201];
int n;
int fx[] = {-1,-1, 0, 0,+1,+1};
int fy[] = {-1, 0,-1,+1, 0,+1};
char opChar;

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
    Point Q[40001], newPoint, qPoint;
    int qPos, qLimit;
    qPos = 0;
    qLimit = 1;
    Q[qPos] = point;
    while(qPos < qLimit){
        qPoint = Q[qPos++];
        visited[qPoint.row][qPoint.col] = 1;
        for(int i = 0; i < 6; i++){
            newPoint.row = qPoint.row + fx[i];
            newPoint.col = qPoint.col + fy[i];
            if(valid(newPoint) && !(visited[newPoint.row][newPoint.col]) && grid[newPoint.row][newPoint.col] == opChar){
                Q[qLimit++] = newPoint;
                visited[newPoint.row][newPoint.col] = 1;
                if(opChar == 'b' && newPoint.row+1 == n) return true;
                if(opChar == 'w' && newPoint.col+1 == n) return true;
            }
        }
    }
    return false;
}


int main(){
   // FILE *in;
    //in = fopen("260.txt","w");

    Point point;
    int count = 1;
    while(cin>>n,n){
        int blackWin = 20000, whiteWin = 20000;
        for(int i = 0; i < n; i++)
            scanf("%s",grid[i]);

        for(int i = 0; i < n; i++){
            opChar ='b';
            if(grid[0][i] == 'b'){
                point.row = 0, point.col = i;
                if(BFS(point)){
                    blackWin = i;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++){
            opChar = 'w';
            if(grid[i][0] == 'w'){
                point.row = i, point.col = 0;
                if(BFS(point)){
                    whiteWin = i;
                    break;
                }
            }
        }
        //fprintf(in,"%d %c\n",count, (blackWin < whiteWin ? 'B' : 'W'));
        cout << count <<" " << (blackWin < whiteWin ? "B" : "W") << endl;
        count++;
    }
   // fclose(in);
    return 0;
}

/*
4
bbwb
wwbw
bwwb
wwbb

*/
