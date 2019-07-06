#include<stdio.h>
#include<string.h>
#define primeNumber 100003
int Hash[1800000];

int hashValue(char line[]){
    int len, hasVal = 0;
    len = strlen(line);
    for(int i = 1; i <= len; i++){
        hasVal += line[i-1]*10 + i;
    }
    return hasVal % primeNumber;
}
int main(){
    char line[33];
    int n, value, i;
    scanf("%d",&n);

    for(i = 0; i < n; i++){
        scanf("%s", line);
        value = hashValue(line);
        if(!Hash[value])
            printf("OK\n");
        else
            printf("%s%d\n", line, Hash[value]);
        Hash[value]++;
    }

    return 0;
}
