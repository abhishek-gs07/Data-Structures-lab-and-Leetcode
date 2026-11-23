#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;};

struct node *reverse(struct node *head){
    struct node *prev=NULL,*curr=head,*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;}

struct node *sortlist(struct node *head){
    struct node *i,*j;
    int temp;
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                temp=j->data;
                j->data=i->data;
                i->data=temp;
            }
        }
    }
    return head;}

struct node *concatenate(struct node *list1,struct node *list2){
    struct node *a=list1,*b=list2,*temp;
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;}
    temp=a;
    while(temp->next!=NULL){
        temp=temp->next;}
    temp->next=b;
    return a;}

void createlist(struct node **head,int n){
    struct node *temp,*newNode;
    int v;
    for(int i=1;i<=n;i++){
        printf("Enter data for node %d: ",i);
        scanf("%d",&v);
        newNode=(struct node *)malloc(sizeof(struct node));
        if(newNode==NULL){printf("Memory allocation failed\n");return;}
        newNode->data=v;
        newNode->next=NULL;
        if(*head==NULL){
            *head=newNode;
        }else{
            temp=*head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;}}}

void display(struct node *head){
    struct node *temp=head;
    if(temp==NULL){printf("List is empty\n");return;}
    printf("Elements of the list are: ");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int ch,n;
    struct node *list1=NULL,*list2=NULL;
    while(1){
        printf("1.Create list1\n");
        printf("2.Create list2\n");
        printf("3.Reverse list1\n");
        printf("4.Sort list1\n");
        printf("5.Sort list2\n");
        printf("6.Concatenate list 1 and 2\n");
        printf("7.Display list1\n");
        printf("8.Display list2\n");
        printf("9.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter number of nodes:");
                    scanf("%d",&n);
                    createlist(&list1,n);
                    break;
            case 2: printf("Enter number of nodes:");
                    scanf("%d",&n);
                    createlist(&list2,n);
                    break;
            case 3: list1=reverse(list1);
                    break;
            case 4: list1=sortlist(list1);
                    break;
            case 5: list2=sortlist(list2);
                    break;
            case 6: list1=concatenate(list1,list2);
                    break;
            case 7: display(list1);
                    break;
            case 8: display(list2);
                    break;
            case 9: return 0;
            default: printf("Invalid choice\n");
        }}
        return 0;}
