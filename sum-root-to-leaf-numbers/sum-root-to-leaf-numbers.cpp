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
    void allNums(vector<string> &res, string curr, TreeNode* currNode){
        if(!currNode){
            return;
        }
        if(!currNode->left){
            string temp= to_string(currNode->val);
            if(!currNode->right){
                res.push_back(curr+temp);
            }
            else{
                allNums(res, curr+temp, currNode->right);
            }
            return;
        }
        
        string temp= to_string(currNode->val);
        allNums(res, curr+temp, currNode->left);
        allNums(res, curr+temp, currNode->right);
        return;
    }
    
public:
    int sumNumbers(TreeNode* root) {
        vector<string> v;
        allNums(v, "", root);
            
        int res=0;
        for(int i=0; i<v.size(); i++){
            int temp= stoi(v[i]);
            res+= temp;
        }
        return res;
    }
};