/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) { // only one node
        if (head->val == val) {
            head = NULL;
        }
        return head;
    }
    struct ListNode *temp = head;
    while (temp->next != NULL) {
        if (temp->next->val == val) {
            struct ListNode *deltemp = temp->next;
            temp->next = deltemp->next;
            free(deltemp);
        }
        else {
            temp = temp->next;
        }
    }
    while (head != NULL && head->val == val) { //to handle deletion at first node
        struct ListNode *deltemp = head;
        head = head->next;
        free(deltemp);
    }

    return head;
}
