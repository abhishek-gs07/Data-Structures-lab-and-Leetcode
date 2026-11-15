struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        return head;
    }
    struct ListNode* temp=head;
    while(temp!=NULL){
        if(temp->next==NULL){
            return head;
        }
        if(temp->next->val==temp->val){
            struct ListNode *deltemp=NULL;
            deltemp=temp->next;
            temp->next=deltemp->next;
            free(deltemp);
        }
        temp=temp->next;
    }
    return head;
}
