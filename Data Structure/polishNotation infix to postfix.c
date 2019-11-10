#include<stdio.h>
char stack[100];
int sPos = 0;
int isExpression(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(')
        return 1;
    return 0;
}
int main(){
    char inputExpression[100] = "A+(B*C-(D/E*F)*G)*H";
    char postNotation[100], ch;
    int len, i, notationPos = 0;
    len = strlen(inputExpression);
    inputExpression[len] = ')';
    inputExpression[len+1] = '\0';
    stack[sPos++] = '(';
    //puts(inputExpression);
    for(i = 0; inputExpression[i] != '\0'; i++){
        if (isExpression(inputExpression[i])) {
            stack[sPos++] = inputExpression[i];
        } else if (inputExpression[i] == ')') {
            while(stack[sPos-1]!='('){
            printf("%c", stack[sPos - 1]);
                postNotation[notationPos++] = stack[--sPos];
                if (sPos == 1) break;

            }
            sPos--;
            printf("\n");
        } else {
            postNotation[notationPos++] = inputExpression[i];
        }
        postNotation[notationPos] = '\0';
    }
    puts(postNotation);
    return 0;
}
