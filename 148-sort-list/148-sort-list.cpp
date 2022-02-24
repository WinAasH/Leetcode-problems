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
private:
    ListNode* merge(ListNode* L1, ListNode* L2){
        if(L1==NULL)    return L2;
        if(L2==NULL)    return L1;
        ListNode *temp;
        if(L1->val < L2->val){
            temp= L1;
            L1= L1->next;
        }
        else{
            temp= L2;
            L2= L2->next;
        }
        ListNode *ans= temp;
        while(L1  &&  L2){
            if(L1->val < L2->val){
                temp->next= L1;
                L1= L1->next;
                temp= temp->next;
            }
            else{
                temp->next= L2;
                L2= L2->next;
                temp= temp->next;
            }
        }
        if(L1)  temp->next= L1;
        else    temp->next= L2;
        return ans;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL  ||  head->next==NULL)  return head;
        ListNode *fast= head, *slow= head, *prev= NULL;
        while(fast){
            prev= slow;
            slow= slow->next;
            fast= fast->next;
            if(fast){
                fast= fast->next;
            }
        }
        prev->next= NULL;
        ListNode *L1= sortList(head);
        ListNode *L2= sortList(slow);
        return merge(L1, L2);
    }
};