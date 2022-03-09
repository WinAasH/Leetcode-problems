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
    ListNode* deleteDuplicates(ListNode* head) {
        // if(!head  ||  !head->next) return head;
        // ListNode *ans= new ListNode(0, head);
        // ListNode *curr= head, *pre= ans;
        // while(curr  &&  curr->next){
        //     ListNode *nextNode= curr->next;
        //     if(curr->val != nextNode->val){
        //         pre= curr;
        //         curr= pre->next;
        //     }
        //     else{
        //         while(curr->val == nextNode->val){
        //             curr= nextNode;
        //             nextNode= curr->next;
        //             if(!nextNode  ||  curr->val != nextNode->val){
        //                 pre->next= nextNode;
        //                 curr= nextNode;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return ans->next;
        
        
        
        if(head==NULL  ||  head->next==NULL)    return head;
        ListNode *dummy= new ListNode(-101, head);
        ListNode *curr= head, *prev= dummy;
        while(curr  &&  curr->next){
            ListNode *nextNode= curr->next;
            if(curr->val!= nextNode->val){
                prev->next= curr;
                prev= curr;
                curr= nextNode;
            }
            else{
                while(curr->val==nextNode->val){
                    curr= nextNode;
                    nextNode= nextNode->next;
                    if(nextNode==NULL  ||  curr->val != nextNode->val){
                        prev->next= nextNode;
                        curr= nextNode;
                        break;
                    }
                }
            }
        }
        return dummy->next;
    }
};