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
    int getDecimalValue(ListNode* head) {
        ListNode *prev= NULL, *curr= head;
        while(curr){
            ListNode *nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }
        
        int ans= 0, base= 0;
        while(prev){
            int temp= pow(2, base);
            int currVal= prev->val;
            ans+= currVal*temp;
            base++;
            prev= prev->next;
        }
        
        return ans;
    }
};