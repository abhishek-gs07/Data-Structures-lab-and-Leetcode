#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;};

void createDLL(struct node **head,int value){
    int v;
    for(int i=1;i<=value;i++){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){printf("Memory allocation failed\n");return;}
    printf("Enter data for node %d: ",i);
    scanf("%d",&v);
    newNode->data=v;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(*head==NULL){
    *head=newNode;}
    else{
    struct node *temp=*head;
    while(temp->next!=NULL)
        temp=temp->next;
    newNode->prev=temp;
    temp->next=newNode;}}}

void insertleft(struct node **head,int value,int n){
    struct node *temp=*head;
    while(temp!=NULL && temp->data!=n){
        temp=temp->next;}
    if(temp==NULL){printf("Node not found\n");return;}
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){printf("Memory allocation failed\n");return;}
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=temp->prev;
    if(temp->prev==NULL)
       *head=newNode;
    else
        temp->prev->next=newNode;
    temp->prev=newNode;
    newNode->next=temp;
}

void deleteVLL(struct node **head,int value){
    struct node *temp=*head;
    if(temp==NULL){
        printf("List is empty! No value to delete!!\n");
        return;}
    while(temp!=NULL && temp->data!=value)
        temp=temp->next;
    if(temp==NULL){
        printf("Node not found\n");
        return;}
    if(temp->prev==NULL){
        *head=temp->next;}
    else
        temp->prev->next=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    free(temp);}

void display(struct node *head){
    struct node *temp=head;
    if(temp==NULL){
        printf("List is empty!\n");
        return;}
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;}
    printf("NULL\n");}

int main(){
    int ch,n,nodev;
    struct node *head=NULL;
    printf("Operations on Doubly Linked List\n");
    while(1){
        printf("1.Create list\n");
        printf("2.Insert at the left of a node\n");
        printf("3.Delete a node\n");
        printf("4.Display list\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter number of nodes:");
                    scanf("%d",&n);
                    createDLL(&head,n);
                    break;
            case 2: printf("Enter data for node: ");
                    scanf("%d",&n);
                    printf("Enter the node's data: ");
                    scanf("%d",&nodev);
                    insertleft(&head,n,nodev);
                    break;
            case 3: printf("Enter the data to be deleted: ");
                    scanf("%d",&n);
                    deleteVLL(&head,n);
                    break;
            case 4: display(head);
                    break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }}
        return 0;}
