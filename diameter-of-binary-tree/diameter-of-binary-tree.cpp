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
    int depth(TreeNode* r){
        if(r==NULL){
            return 0;
        }
        
        return 1+max(depth(r->left), depth(r->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int dia= depth(root->left)+ depth(root->right);
        
        int leftDia= diameterOfBinaryTree(root->left);
        int rightDia= diameterOfBinaryTree(root->right);
        
        return max(dia, max(leftDia, rightDia));
    }
};