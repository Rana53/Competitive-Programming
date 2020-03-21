#include<stdio.h>
#include<string.h>

char encoding(char *text);

int main(){
    char text[1000];
    scanf("%[^\n]",text);
    encoding(text);
    return 0;
}

char encoding(char *text){
    char enText[1000], sing[1000];
    int l, signOccure[1000];
    l = strlen(text);
    printf("%d\n",l);
    return 'a';
}
