#include <stdio.h>
#define MAX 5

int circularq[MAX], front=-1,rear=-1;

void Insert(int ele){
        if(front ==(rear+1)%MAX){
            printf("Queue Overflow\n");}
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%MAX;
        circularq[rear]=ele;
    }

void Delete(){
    if(front==-1 && rear==-1){
       printf("Queue Underflow\n");}
    else{
        printf("Deleted element is: %d ",circularq[front]);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%MAX;
        }
    }}

void Display(){
    if(front==-1){
        printf("Queue is empty\n");}
    else{
        int i=front;
        printf("Elements of the circular queue are:\n");
        while(i!=rear){
            printf("%d ",circularq[i]);
            i=(i+1)%MAX;
        }
        printf("%d ",circularq[i]);
        printf("\n");
    }}


int main() {
    int ch,x;
    while (1) {
        printf("Circular queue operations:\n");
        printf("1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1: printf("Enter a value: ");
                scanf("%d", &x);
                Insert(x);
                break;
        case 2: Delete();
                break;
        case 3: Display();
                break;

        case 4: return 0;

        default: printf("Invalid choice\n");
        }
    }
}
