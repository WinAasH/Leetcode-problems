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
    vector<TreeNode*> generateAllBST(int l, int r){
        if(l>r){
            return {NULL};
        }
        vector<TreeNode*> result;
        for(int root=l; root<=r; root++){
            vector<TreeNode*> left= generateAllBST(l, root-1);
            vector<TreeNode*> right= generateAllBST(root+1, r);
            for(TreeNode* leftNode: left){
                for(TreeNode* rightNode: right){
                    TreeNode* curr= new TreeNode(root);
                    curr->left= leftNode;
                    curr->right= rightNode;
                    result.push_back(curr);
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateAllBST(1, n);
    }
};