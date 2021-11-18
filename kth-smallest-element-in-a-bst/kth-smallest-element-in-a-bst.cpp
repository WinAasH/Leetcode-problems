class Solution {
public:
    int a = INT_MIN;
    int curr = 1;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return a;
    }
    void inorder(TreeNode* root,int &k){
        if(!root) return;
        inorder(root->left,k);
        if(curr == k) a = root->val;
        curr++;
        inorder(root->right,k);
    }
};