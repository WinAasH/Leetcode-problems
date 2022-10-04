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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root  &&  root->left==NULL  &&  root->right==NULL  &&  targetSum==root->val){
            return true;
        }
        else if(root==NULL){
            return false;
        }
        int temp= targetSum- root->val;
        return hasPathSum(root->left, temp)  ||  hasPathSum(root->right, temp);
    }
};