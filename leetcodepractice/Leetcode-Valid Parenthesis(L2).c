//Valid Parenthesis
#include<stdio.h>
#include<string.h>

#define MAX 25
char parenthesis[MAX];
char Stack[MAX];
int top=-1,i=0;

int isValid(){
    while(parenthesis[i]!='\0'){
        if(parenthesis[i]=='('||parenthesis[i]=='['||parenthesis[i]=='{'){
            Stack[++top]=parenthesis[i++];}
        else{
            if(top==-1)
                return 0;
            char c=parenthesis[i++];
            char t=Stack[top--];
            if(c=='(' && t!=')')
                return 0;
            if(c=='{' && t!='}')
                return 0;
            if(c=='[' && t!=']')
                return 0;}}
    return top==-1;}

int main(){
    printf("Enter String of Parenthesis \n");
    scanf("%s",parenthesis);
    printf(isValid()?"\nValid":"\nNot Valid");
    return 0;}
