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
    bool check(TreeNode* prev, TreeNode *curr, int Sum, int target){
        if(!curr){
            if(Sum==target  &&  prev->left==NULL  &&  prev->right==NULL){
                return true;
            }
            return false;
        }
        
        int tempSum= Sum+curr->val;
        bool L= check(curr, curr->left, tempSum, target);
        bool R= check(curr, curr->right, tempSum, target);
        return (L||R);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        return (check(root, root->left, root->val, targetSum)||check(root, root->right, root->val, targetSum));
    }
};