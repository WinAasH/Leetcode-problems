/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int totalSum= 0;
    void numbers(TreeNode *curr, int currVal){
        if(!curr){
            return;
        }
        currVal+= curr->val;
        if(!curr->left  &&  !curr->right){
            totalSum+= currVal;
            return;
        }
        numbers(curr->left, currVal*2);
        numbers(curr->right, currVal*2);
        return;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)   return 0;
        numbers(root, 0);
        return totalSum;
    }
};