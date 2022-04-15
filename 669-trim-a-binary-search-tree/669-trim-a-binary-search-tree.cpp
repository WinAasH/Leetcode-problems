class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //if the node is nullptr then we have nothing to trim
        if(!root) return root;
        
        //if the current nodes value is less than lower then all its left are lower than low 
        // so we can discarts its left childrens
        // and we can return right child trimming all elements
        if(root->val < low) return trimBST(root->right,low,high);
        
        //like wise the left 
        if(root->val > high) return trimBST(root->left,low,high);
        
        //else trim left and right child
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        return root;
    }
};