class Solution {
private:
    vector<vector<int>> ans;
    void zigzag(TreeNode* root, int depth){
        if(root==NULL) return;
        if(ans.size() <= depth)
            ans.push_back(vector<int>{root->val});
        else 
            ans[depth].push_back(root->val);
        zigzag(root->left, depth+1);
        zigzag(root->right, depth+1);
        return;           
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzag(root, 0);
        for(int i=1; i<ans.size(); i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};