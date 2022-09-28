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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head  ||  !head->next){
            return NULL;
        }
        
        ListNode *curr= head;
        int len=0;
        while(curr){
            len++;
            curr= curr->next;
        }
        
        int temp= len-n;
        if(temp==0){
            return head->next;
        }
        curr= head;
        for(int i=1; i<temp; i++){
            curr= curr->next;
        }
        
        curr->next= curr->next->next;
        return head;
    }
};