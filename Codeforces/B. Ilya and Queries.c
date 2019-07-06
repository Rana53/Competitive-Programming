#include<stdio.h>
#include<string.h>
int main(){
    char line[200001];
    int count[200001], m, len, l, r;

    scanf("%s", line);
    scanf("%d", &m);
    len = strlen(line);

    if(line[0] == line[1]) count[0] = 1;
    else count[0] = 0;

    for(int i = 1; i < len - 1; i++){
        if(line[i] == line[i + 1])
            count[i] = count[i-1] + 1;
        else
            count[i] = count[i-1];
    }
    count[len-1] = count[len-2];

    for(int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        if(!(l-1))
            printf("%d\n",count[r-2]);
        else
            printf("%d\n", count[r-2] - count[l - 2]);
    }

    return 0;
}
