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
    TreeNode *buildTree(vector<int> &nums, int start, int end){
        if(end<start)   return NULL;
        int mid= (start+end)/2;
        TreeNode *curr= new TreeNode(nums[mid]);
        curr->left= buildTree(nums, start, mid-1);
        curr->right= buildTree(nums, mid+1, end);
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};