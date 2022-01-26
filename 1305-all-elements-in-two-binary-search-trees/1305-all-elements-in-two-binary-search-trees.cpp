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
    void inorder(TreeNode *curr, vector<int> &v){
        if(!curr)   return;
        inorder(curr->left, v);
        v.push_back(curr->val);
        inorder(curr->right, v);
        return;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        inorder(root1, v);
        inorder(root2, v);
        sort(v.begin(), v.end());
        return v;
    }
};