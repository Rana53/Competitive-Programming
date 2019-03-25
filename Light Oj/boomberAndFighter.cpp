#include<stdio.h>
int main(){
    char ch;
    int a , b;
    FILE *fp;
    fp = fopen("text.txt","r");
    if(fp == NULL){
        printf("File can't open\n");
        //exit(EXIT_FAILURE);
    }
    else{
        while(fgetc(fp) != EOF){
          fscanf(fp, "%d%d",&a, &b);
          printf("a = %d  b = %d\n", a, b);
        }
        fclose(fp);
    }

    return 0;
}
