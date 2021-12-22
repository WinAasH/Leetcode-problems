/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head  ||  !head->next  ||  !head->next->next) return;
        
        ListNode *slow= head, *fast= head, *slowPrev= NULL;
        while(fast!=NULL  &&  fast->next!=NULL){
            slowPrev= slow;
            slow= slow->next;
            fast= fast->next;
            if(fast) fast= fast->next;
        }
        slowPrev->next= NULL;
        
        
        ListNode *res= head, *curr= slow, *prev= NULL;
        while(curr){
            ListNode* nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }
        
        ListNode *mergedHead= new ListNode(-1);
        ListNode *L= mergedHead;
        ListNode *L1= head, *L2= prev;
        while(L1  &&  L2){
            L->next= L1;
            L1= L1->next;
            L= L->next;
            L->next= L2;
            L2= L2->next;
            L= L->next;
        }
        
        head= mergedHead->next;
    }
};