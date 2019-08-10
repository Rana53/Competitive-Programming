#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int graph[27][27];
int sz[27];

int main(){
    int n;
    char start, input[2], ch;
    cin >> n;
    while(n--){
        memset(graph,0,sizeof(graph));
        memset(sz,0,sizeof(sz));
        cin >> start;
        cin.get();
        cout << "start inpu - " << start << endl;
        while(scanf("%[^\n]",input)){
            if(input[0] == '\n') break;
            cout <<" " -  input << endl;
        }
        cout << "input end" << endl;
    }

}
