#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    while(n--){
        cin >> m;
        int ara[m];
        for(int i = 0; i < m; i++)
            cin >> ara[i];
        sort(ara,ara+m);
        int person1 , person2;
        person1 = 0;
        person2 = 0;
        for(int i = m - 1 ; i >= 0; --i){
            if(person1< person2)
                person1 += ara[i];
            else
                person2 += ara[i];
        }
        cout << abs(person1-person2) << endl;
    }


}
