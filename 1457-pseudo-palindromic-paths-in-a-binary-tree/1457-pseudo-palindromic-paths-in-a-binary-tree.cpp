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
    int dfs(TreeNode *root, vector<int> &a){
        if(root==NULL)  return 0;
        a[root->val]++;
        int ans= dfs(root->left, a)+ dfs(root->right, a), odd= 0;
        for(int i=1; i<=9; i++)  if(a[i]%2)  odd++;
        a[root->val]--;
        if(root->left==NULL  &&  root->right==NULL  &&  odd<=1) ans++;
        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> a(10, 0);
        return dfs(root, a);
    }
};