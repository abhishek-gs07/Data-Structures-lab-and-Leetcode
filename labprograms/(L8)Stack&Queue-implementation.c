#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;};

struct node *top=NULL;
struct node *front=NULL, *rear=NULL;

void push(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;}
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}

void pop(){
    struct node *temp=top;
    if(top==NULL){
        printf("Stack underflow\n");
        return;}
    top=top->next;
    printf("Popped element: %d\n",temp->data);
    free(temp);
}

void showStack(){
    struct node *temp=NULL;
    if(top==NULL){
        printf("Stack is empty\n");
        return;}
    printf("Elements of Stack are: ");
    temp=top;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");}

void enqueue(int x){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=x;
    newNode->next=NULL;
    if(rear==NULL){
        rear=newNode;
        front=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;}
}

void dequeue(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;}
    struct node* newNode=front;
    front=front->next;
    printf("Deleted element: %d\n",newNode->data);
    free(newNode);
    if(front==NULL){
        rear=NULL;
    }}

void showQueue(){
    if(front==NULL){
        printf("queue is empty\n");
        return;}
    struct node *temp=front;
    printf("Elements of queue are: ");
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");}

int main(){
    int ch,t,c;
    while(1){
    printf("1.Stack \n2.Queue\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    if(c==1){
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1: printf("Enter element to be pushed:");
                scanf("%d",&t);
                push(t);
                break;
        case 2: pop();
                break;
        case 3: showStack();
                break;
        case 4: return 0;
        default : printf("Invalid choice\n");}}
    else if(c==2){
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter element to be inserted:");
                    scanf("%d",&t);
                    enqueue(t);
                    break;
            case 2: dequeue();
                    break;
            case 3: showQueue();
                    break;
            case 4: return 0;
            default : printf("Invalid choice\n");}}
    else{
        printf("Invalid choice!\n");}}}
