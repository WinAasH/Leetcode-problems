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
    bool check(TreeNode *curr, TreeNode *currSub){
        if(currSub==NULL  ||  curr==NULL) return currSub==NULL  &&  curr==NULL;
        else if(curr->val == currSub->val) return check(curr->left, currSub->left)  &&  check(curr->right, currSub->right);
        else return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        else if(check(root, subRoot))  return true;
        else    return (isSubtree(root->left, subRoot)  ||  isSubtree(root->right, subRoot));
    }
};