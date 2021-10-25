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
    vector<int> ans;
    
    void preorder(TreeNode *curr){
        if(!curr){
            return;
        }
        ans.push_back(curr->val);
        preorder(curr->left);
        preorder(curr->right);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
};