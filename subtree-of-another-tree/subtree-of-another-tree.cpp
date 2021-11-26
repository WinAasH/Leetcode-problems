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
    bool check(TreeNode *curr, TreeNode *currSub){
        if(!currSub  &&  !curr) return true;
        if(!currSub) return false;
        if(!curr) return false;
        if(curr->val != currSub->val) return false;
        
        return check(curr->left, currSub->left)  &&  check(curr->right, currSub->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        
        if(!root) return false;
        
        if(root->val == subRoot->val){
            bool temp= check(root, subRoot);
            return (temp  ||  isSubtree(root->left, subRoot)  ||  isSubtree(root->right, subRoot));
        }
        
        return (isSubtree(root->left, subRoot)  ||  isSubtree(root->right, subRoot));
    }
};