#include<stdio.h>
#include<conio.h>
#define MAX 5
int Stack[MAX];
int top=-1;
void push(int ele){
    if(top==MAX-1){
        printf("Stack Overflow\n");}
    else{
        top=top+1;
        Stack[top]=ele;}}
void pop(){
    int temp;
    if(top==-1){
        printf("Stack Underflow\n");}
    else{
        temp=Stack[top];
        top=top-1;
        printf("Popped element is: %d \n",temp);}}
void Display(){
    int j;
    if(top==-1){
        printf("Stack Underflow \n");}
    else{
        printf("Elements of Stack are:\n");
        for(j=top;j>=0;j--){
            printf("%d  ",Stack[j]);}
        printf("\n");}}
int main(){
    int choice,ele;
    while(1){
        printf("Stack Operations:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter an element to be inserted\n");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2: pop();
                    break;
            case 3: Display();
                    break;
            case 4: return 0;
                    break;
            default: printf("Invalid choice\n");
                     break;}}
        return 0;
}
