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
    TreeNode* helper(vector<int> &preorder, int preS, int preE, vector<int> &inorder, int inS, int inE, map<int, int> &mp){
        if(preS>preE  ||  inS>inE)  return NULL;
        
        TreeNode *curr= new TreeNode(preorder[preS]);
        
        int n= mp[preorder[preS]];
        
        curr->left= helper(preorder, preS+1, preS+n-inS, inorder, inS, n-1, mp);
        curr->right= helper(preorder, preS+n-inS+1, preE, inorder, n+1, inE, mp);
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        
        for(int i=0; i<preorder.size(); i++){
            mp[inorder[i]]= i;
        }
        
        TreeNode *ans= helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return ans;
    }
};