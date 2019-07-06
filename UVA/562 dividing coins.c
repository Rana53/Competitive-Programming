#include<stdio.h>
int maxValueInArray(int *ara, int n){
    int maxValue = 0;
    for(int i = 0; i < n; i++){
        if(ara[i]>maxValue)
            maxValue = ara[i];
    }
    return maxValue;
}

void sortArray(int *ara, int n){
    int  output[n];
    int maxVal = maxValueInArray(ara,n);
    int count[maxVal+1];

    for(int i = 0; i <= maxVal; i++)
        count[i] = 0;
    for(int i = 0; i < n; i++)
        count[ara[i]]++;
    for(int i = 1; i <= maxVal;i++)
        count[i] += count[i-1];
    for(int i = 0; i < n; i++){
        output[count[ara[i]]-1] = ara[i];
        --count[ara[i]];
    }
    for(int i = 0; i < n; i++)
        ara[i] = output[i];
}

int main(){
    int n, m,ara[100], person1, person2;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(int i = 0; i < m; i++)
            scanf("%d",&ara[i]);
        sortArray(ara,m);

        for(int i = 0; i < m; i++)
            printf(" %d",ara[i]);
        printf("-------\n");

        person1 = 0;
        person2 = 0;
        for(int i = m - 1; i >= 0; i--){
            if(person1 > person2)
                person2 += ara[i];
            else
                person1 += ara[i];
        }
        printf("%d\n", person1>person2?person1-person2:person2-person1);
    }
    return 0;
}
