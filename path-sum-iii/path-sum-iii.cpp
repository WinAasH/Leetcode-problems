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
    int count= 0;
    void allPath(TreeNode *curr, int targetSum){
        if(!curr) return;
        
        if(curr->val == targetSum) count++;
        
        allPath(curr->left, targetSum-(curr->val));
        allPath(curr->right, targetSum-(curr->val));
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        allPath(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};