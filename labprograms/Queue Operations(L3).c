#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Queue[MAX];
int front=-1;
int rear=-1;

void Enqueue(int ele){
    if(rear==MAX-1){
        printf("Queue Overflow \n");}
    else if(front==-1){
        front=0;
        rear=0;
        Queue[rear]=ele;}
    else{
        rear=rear+1;
        Queue[rear]=ele;}}

void Dequeue(){
    if(front==-1 || front>rear){
        printf("Queue Underflow \n");}
    else if(front==rear){
        printf("Deleted item is: %d\n",Queue[front]);
        front=rear=-1;}
    else{
        printf("Deleted item is: %d\n",Queue[front]);
        front--;}}

void display(){
    if(front==-1 || front>rear)
        printf("Queue Underflow/ Queue is Empty\n");
    else{
        printf("Queue elements are:\n");
        for(int i=front;i<=rear;i++){
            printf(" %d    ",Queue[i]);}}}

int main(){
    int choice,element;
    while(1){
        printf("\nQueue Operations\n");
        printf(" 1.Enqueue \n 2.Dequeue\n 3.Display\n 4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter element to be inserted into the queue\n");
                scanf("%d",&element);
                Enqueue(element);
                break;
        case 2: Dequeue();
                break;
        case 3: display();
                break;
        case 4: exit(0);
        default: printf("Invalid choice\n");
                 break;}}
        return 0;}
