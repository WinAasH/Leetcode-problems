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
    bool check(ListNode* root,ListNode* head,ListNode** temp){
        if(head==NULL){
            *temp=root;;
            return 1;
        }
        ListNode* t;
        bool ans;
        ans=check(root,head->next,&t);
        *temp=t->next;
        if(head->val==t->val){
            return true&&ans;
        }
        return false;
    }
    
    bool isPalindrome(ListNode* head) {
        return(check(head,head,&head));   
    }
};