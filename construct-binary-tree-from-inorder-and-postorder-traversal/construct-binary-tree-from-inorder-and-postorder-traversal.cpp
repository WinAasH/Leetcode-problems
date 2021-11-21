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
    int pos;
    TreeNode *build(vector<int> &in, vector<int> &post, int start, int end){
        if(pos<0  ||  start>end) return NULL;
        
        int value= post[pos];
        pos--;
        
        TreeNode *curr= new TreeNode(value);
        
        int i=start;
        for(; i<end; i++) if(in[i]==value) break;
        
        TreeNode *right= build(in, post, i+1, end);
        TreeNode *left= build(in, post, start, i-1);
        
        curr->right= right;
        curr->left= left;
        return curr;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pos= postorder.size()-1;
        TreeNode *root= build(inorder, postorder, 0, inorder.size()-1);
        return root;
    }
};