#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteEnd(struct Node **head, int value){
    struct Node *prev, *temp;
    if(*head==NULL){
        printf("List is empty \n");
        return;
    }
    temp=*head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;}
    if(temp->next==NULL){
        printf("Deleted element is %d \n",temp->data);
        prev->next=NULL;
        free(temp);
        return;
    }}

void createList(struct Node **head, int n) {
    struct Node *newNode, *temp;
    int i, value;
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d : ", i);
        scanf("%d", &value);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = value;
        newNode->next = NULL;
        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void deleteBeginning(struct Node **head) {
    struct Node *temp;
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    temp=*head;
    if(temp->next==NULL){
        printf("Deleted element is %d ",temp->data);
        *head=NULL;
        free(temp);}
    temp=temp->next;
    *head=temp;
    free(temp);}

void deleteMiddle(struct Node **head, int value) {
    struct Node *temp, *prev;
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    temp = *head;
    if(temp->data==value){
        *head=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        if(temp->data==value){
            printf("Deleted element is %d \n",temp->data);
            free(temp);
            prev->next=temp->next;
            return;
        }}
    if(temp->next==NULL){
        printf("No such Node found\n");
        return;
    }
}

void display(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, value, position, n;
    while (1) {
        printf("Singly-Linked-List");
        printf("\n1. Create List");
        printf("\n2. Delete at Beginning");
        printf("\n3. Delete a Value in list");
        printf("\n4. Delete at End");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter the number of nodes: ");
                    scanf("%d", &n);
                    if (n < 0) {
                        printf("Invalid number of nodes!\n");
                        break;
                    } else {
                        createList(&head, n);
                    }
                    break;
            case 2: deleteBeginning(&head);
                    break;
            case 3: printf("Enter the value to be deleted: ");
                    scanf("%d",&value);
                    deleteMiddle(&head, value);
                    break;
            case 4: deleteEnd(&head, value);
                    break;
            case 5: display(head);
                    break;
            case 6: printf("Exiting program.\n");
                    return 0;
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
