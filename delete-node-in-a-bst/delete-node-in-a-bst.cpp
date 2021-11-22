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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val < key){
            root->right= deleteNode(root->right, key);
            return root;
        }
        else if(root->val > key){
            root->left= deleteNode(root->left, key);
            return root;
        }
        else if(root->val == key){
            if(!root->left  &&  !root->right) return NULL;
            else if(!root->left) return root->right;
            else if(!root->right) return root->left;
            else{
                TreeNode *after= root->left;
                while(after  &&  after->right) after= after->right;
                after->right= root->right;
                return root->left;
            }
        }
        
        return root;
    }
};