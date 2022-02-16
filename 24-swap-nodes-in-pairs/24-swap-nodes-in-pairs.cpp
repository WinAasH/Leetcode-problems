class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* current = dummy;
        while(current -> next != NULL && current->next->next != NULL){
            ListNode* first = current-> next;
            ListNode* second = current -> next -> next;
            first -> next = second -> next;
            current -> next = second;
            second -> next = first;
            current = current -> next -> next;
        }
        return dummy -> next;
    }
};