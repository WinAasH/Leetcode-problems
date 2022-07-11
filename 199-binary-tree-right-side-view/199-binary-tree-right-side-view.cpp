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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<int>ans;
        
        
        while(!q.empty()) {
            TreeNode *curr = q.front().first;
            int curr_height = q.front().second;
            q.pop();
            
           if(curr_height < ans.size()) {
               ans[ans.size()-1] = curr->val;
           } else {
               ans.push_back(curr->val);
           }
            
            if(curr->left) {
                q.push({curr->left,curr_height+1});
            } 
            if(curr->right) {
                q.push({curr->right,curr_height+1});
            }
        }
		
        return ans;
    }
};