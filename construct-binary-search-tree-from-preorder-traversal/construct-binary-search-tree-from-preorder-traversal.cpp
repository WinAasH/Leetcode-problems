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
    TreeNode *put(TreeNode *root, int x){
        if(root==NULL){
            TreeNode *curr= new TreeNode(x);
            return curr;
        }
        if(x> root->val){
            root->right= put(root->right, x);
        }
        else{
            root->left= put(root->left, x);
        }
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root= new TreeNode(preorder[0]);
        int len= preorder.size();
        
        for(int i=1; i<len; i++){
            put(root, preorder[i]);
        }
        
        return root;
    }
};