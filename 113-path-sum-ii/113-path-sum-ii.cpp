class Solution {
public:
    void pathDhundho(TreeNode* root,int targetSum,int &sum,vector<int>&v,vector<vector<int>>&ans)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            if(sum+root->val == targetSum)
            {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        sum += root->val;
        v.push_back(root->val);
        pathDhundho(root->left,targetSum,sum,v,ans);
        pathDhundho(root->right,targetSum,sum,v,ans);
        sum -= root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        vector<vector<int>> ans;
        int sum=0;
        pathDhundho(root,targetSum,sum,v,ans);
        return ans;
    }
};