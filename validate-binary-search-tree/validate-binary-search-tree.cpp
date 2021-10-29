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
    bool validate(TreeNode *root, int *max,int *min){
        if(root == NULL){
            return true;
        }else if(max!=NULL && root->val>= *max || min!=NULL && root->val <= *min){
            return false;
        }else{
            return validate(root->left,&(root->val),min) && validate(root->right,max,&(root->val));
        }
    }
    
    bool isValidBST(TreeNode* root) {
        return validate(root,NULL,NULL);
    }
};