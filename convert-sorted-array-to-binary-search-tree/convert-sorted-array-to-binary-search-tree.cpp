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
    TreeNode* buildTree(vector<int> &v, int s, int e){
        if(s>e){
            return NULL;
        }
        
        int mid= (s+e)/2;
        TreeNode *curr= new TreeNode(v[mid]);
        curr->left= buildTree(v, s, mid-1);
        curr->right= buildTree(v, mid+1, e);
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};