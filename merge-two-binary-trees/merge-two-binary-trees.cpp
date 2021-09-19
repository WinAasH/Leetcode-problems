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
    TreeNode* mergeBoth(TreeNode* r1, TreeNode* r2){
        if(r1== NULL  &&  r2== NULL){
            return NULL;
        }
        if(r1== NULL){
            return r2;
        }
        if(r2== NULL){
            return r1;
        }
        TreeNode* curr= new TreeNode(r1->val+r2->val);
        curr->left= mergeBoth(r1->left, r2->left);
        curr->right= mergeBoth(r1->right, r2->right);
        return curr;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergeBoth(root1, root2);
    }
};