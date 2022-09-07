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
public:
    
    void rec(TreeNode* root,string &ans){
        if(root!=NULL){
            ans+=to_string(root->val);
            if(root->left!=NULL){
                ans+='(';
                rec(root->left,ans);
                ans+=')';
            }
            if(root->right!=NULL){
                if(root->left==NULL){
                    ans+="()";
                }
                ans+='(';
                rec(root->right,ans);
                ans+=')';
            }
        }
        return ;
    }
    
    string tree2str(TreeNode* root) {
        string ans="";
        rec(root,ans);
        return ans;
    }
};