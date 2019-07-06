///C code not accepted but C++ Accepted.

#include<stdio.h>
int main(){
    int n, m, prev, big, small, clockWish, antiClockWish;
    long long int allTask;
    scanf("%d %d",&n, &m);
    int ara[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &ara[i]);

    allTask = 0;
    prev = 1;
    for(int i = 0; i < m; i++){
        small = prev;
        big = ara[i];
        if(small > big){
            int tmp = small;
            small = big;
            big = tmp;
        }

        clockWish = big - small;
        antiClockWish = small - 1;
        antiClockWish += n - big + 1;

        if(ara[i] >= prev)
            allTask += clockWish;
        else
            allTask += antiClockWish;

        prev = ara[i];
    }
    printf("%I64d\n",allTask);

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, prev, big, small, clockWish, antiClockWish;
    long long int allTask;
    scanf("%d %d",&n, &m);
    int ara[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &ara[i]);

    allTask = 0;
    prev = 1;
    for(int i = 0; i < m; i++){
        small = prev;
        big = ara[i];
        if(small > big){
            int tmp = small;
            small = big;
            big = tmp;
        }

        clockWish = big - small;
        antiClockWish = small - 1;
        antiClockWish += n - big + 1;

        if(ara[i] >= prev)
            allTask += clockWish;
        else
            allTask += antiClockWish;

        prev = ara[i];
    }
    cout << allTask << endl;

    return 0;
}
*/
