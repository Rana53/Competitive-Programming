#include<bits/stdc++.h>
using namespace std;
struct display{
    int fontSize, cost;
};
bool acompare(display lhs, display rhs) { return lhs.cost < rhs.cost; }

int main(){
    int n, a, b;
    cin >> n;
    display ara[n];
    for(int i = 0; i < n; i++)
        cin >> ara[i].fontSize;
    for(int i = 0; i < n; i++)
        cin >> ara[i].cost;
    sort(ara,ara+n,acompare);

    //for(int i = 0; i < n; i++)
    //    cout << ara[i].cost << endl;
    int mina, minb,minc,gotNum = 1, val;

    mina = ara[0].cost;
    val = ara[0].fontSize;

    int i;
    for(i = 1; i < n; i ++){
        if(ara[i].fontSize != val ){
            val = ara[i].fontSize;
            minb = ara[i].cost;
            gotNum++;
            break;
        }
    }

    for( ; i < n; i++){
        if(ara[i].fontSize != ara[0].fontSize && ara[i].fontSize != val){
            gotNum++;
            minc = ara[i].cost;
            break;
        }
    }
    if(gotNum == 3){
        cout << mina+ minb+minc << endl;
    }
    else
        cout << -1 << endl;
    return 0;

}
