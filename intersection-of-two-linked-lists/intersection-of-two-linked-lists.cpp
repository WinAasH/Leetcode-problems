/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA= headA, *currB= headB;
        while(currA){
            while(currB){
                if(currA == currB){
                    return currA;
                }
                currB= currB->next;
            }
            currB= headB;
            currA= currA->next;
        }
        
        return NULL;
    }
};