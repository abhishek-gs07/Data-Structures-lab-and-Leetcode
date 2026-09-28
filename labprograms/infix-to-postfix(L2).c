//infix to postfix
#include<stdio.h>
#include<string.h>

#define MAX 25
char Stack[MAX];
char expression[MAX];
char postfix[MAX];
int top=-1,pf_index=-1,i=0;

void push_pf(char ele){
    pf_index++;
    postfix[pf_index]=ele;}

void push(char element){
    Stack[++top]=element;}

void parenthesis_condition(){
    while(1){
        postfix[++pf_index]=Stack[top--];
        if(Stack[top]=='('){
            top--;
            break;}}}

void operator_condition(char op){
        if(op=='*'||op=='/'){
            while(1){
                if(Stack[top]=='*'||Stack[top]=='/'){
                    postfix[++pf_index]=Stack[top--];}
                else{
                    Stack[++top]=op;
                    break;}}}
        else {
            while(1){
                if(Stack[top]=='+'||Stack[top]=='-'||Stack[top]=='*'||Stack[top]=='/'){
                    postfix[++pf_index]=Stack[top--];}
                else{
                    Stack[++top]=op;
                    break;}}}}

int main(){
    printf("Enter the infix expression \n");
    scanf("%s",expression);
    while(expression[i]!='\0'){
        if(expression[i]=='('){
            push(expression[i]);}
        else if(expression[i]==')'){
            parenthesis_condition();}
        else if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'){
            operator_condition(expression[i]);}
        else{
            push_pf(expression[i]);}
        i++;}
    /*while(top!=-1){
        postfix[++pf_index]=Stack[top--];}*/
    postfix[++pf_index]='\0';
    printf("\n Postfix expression is: %s",postfix);
    return 0;}
