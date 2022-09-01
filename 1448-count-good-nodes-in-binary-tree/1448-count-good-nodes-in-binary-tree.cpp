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
    int count(TreeNode* &root,int maxi){
        if(root==NULL){
            return 0;
        }
        maxi=max(root->val,maxi);
        if(root->val>=maxi){
            return 1+count(root->left,maxi)+count(root->right,maxi);
        }
        return count(root->left,maxi)+count(root->right,maxi);
        
        
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int max=INT_MIN;
        return count(root,max);
    }
};