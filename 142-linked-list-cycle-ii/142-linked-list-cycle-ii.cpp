class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return NULL;
        while(head->next!=NULL){
            head= head->next;
            if(head >= head->next)    return head->next;
        }
        return NULL;
    }
};