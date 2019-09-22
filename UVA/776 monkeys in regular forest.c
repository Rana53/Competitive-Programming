#include<stdio.h>
#include<string.h>

char Graph[100][100];
int grid[100][100];
int col, row;
int fx[8] = {-1,-1,-1,0,+1,+1,+1,0};
int fy[8] = {-2,0,+2,+2,+2,0,-2,-2};

int valid(int i, int j){
    if(i < 0 || row <= i)
        return 0;
    if(j < 0 || col <= j)
        return 0;
    return 1;
}
void printResult(){
    int align[col];
    memset(align, 0, sizeof(align));

        for(j = 0; j < col; j+= 2){
            for(i = 0; i < row; i++){
                if(align[i][j] <= grid[i][j])
                    align[i][j] = grid[i][j];
                    align[i][j] = grid[i][j];
            }
        }
    }
    int i , j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++)
            printf(" %d", grid[i][j]);
        printf("\n");
    }

}

void DFS(int val, char u, int i, int j){
    int k, ii, jj;
    if(!valid(i,j))
        return ;
    if(grid[i][j])
        return;
    grid[i][j] = val;
    for(k = 0; k < 8; k++){
        ii = i + fx[k];
        jj = j + fy[k];

        if(!grid[ii][jj] && Graph[ii][jj] == u)
            DFS(val,u,ii,jj);
    }
}
void processInput(int size){
    int check[70], count, i , j, len;
    char u;
    memset(check,0,sizeof(check));
    memset(grid, 0, sizeof(grid));

    len = strlen(Graph[0]);
    col = len;
    row = size;
    count = 1;
    for(i = 0; i < size; i++){
        for(j = 0; j < len; j+= 2){
            u = Graph[i][j];
            if(!check[u-'A'])
                check[u-'A'] = count++;
            DFS(check[u-'A'],u,i,j);
        }
    }
    printResult();
}

int main(){
    char line[100];
    int index = 0;
    while(gets(Graph[index])){
        if(Graph[index][0] == '\0'){
            processInput(index);
            break;
        }
        if(Graph[index][0] == '%'){
            processInput(index);
            index = -1;
        }
        index++;
    }

    return 0;
}
