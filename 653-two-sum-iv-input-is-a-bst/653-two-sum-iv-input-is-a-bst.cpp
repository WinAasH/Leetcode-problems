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
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return 0;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        unordered_set<int> st;
        while(!q.empty()){
            int len= q.size();
            while(len>0){
                len--;
                TreeNode *temp= q.front();
                q.pop();
                if(st.find(temp->val)!=st.end()){
                    return true;
                }
                st.insert(k - temp->val);
                
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        
        return false;
    }
};