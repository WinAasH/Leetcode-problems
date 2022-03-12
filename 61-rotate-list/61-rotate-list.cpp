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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)  return head;
        int len= 0;
        ListNode *curr= head, *prev;
        while(curr){
            curr= curr->next;
            len++;
        }
        k%= len;
        if(k==0)    return head;
        k= len-k;
        curr= head;
        while(k--){
            prev= curr;
            curr= curr->next;
        }
        prev->next= NULL;
        ListNode *newHead= curr;
        while(curr){
            prev= curr;
            curr= curr->next;
        }
        prev->next= head;
        return newHead;
    }
};