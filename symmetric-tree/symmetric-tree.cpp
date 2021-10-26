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
    bool check(TreeNode *L, TreeNode *R){
        if(!L  &&  !R){
            return true;
        }
        else if(L  &&  R){
            return ((L->val == R->val)  &&  check(L->right, R->left)  &&  check(L->left, R->right));
        }
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return (!root  ||  check(root->left, root->right));
    }
};