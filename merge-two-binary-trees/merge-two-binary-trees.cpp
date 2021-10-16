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
    TreeNode* merge(TreeNode* r1, TreeNode* r2){
        if(!r1){
            return r2;
        }
        
        if(!r2){
            return r1;
        }
        
        TreeNode *root= new TreeNode(r1->val + r2->val);
        root->left= merge(r1->left, r2->left);
        root->right= merge(r1->right, r2->right);
        
        return root;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1){
            return root2;
        }
        
        if(!root2){
            return root1;
        }
        
        return merge(root1, root2);
    }
};