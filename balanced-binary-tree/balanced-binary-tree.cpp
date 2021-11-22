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
    int depth(TreeNode *curr){
        if(!curr) return 0;
        
        return 1+ max(depth(curr->left), depth(curr->right));
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int L= depth(root->left);
        int R= depth(root->right);
        if(L==R) return isBalanced(root->left)  &&  isBalanced(root->right);
        else if(abs(L-R)==1) return isBalanced(root->left)  &&  isBalanced(root->right);
        return false;
    }
};