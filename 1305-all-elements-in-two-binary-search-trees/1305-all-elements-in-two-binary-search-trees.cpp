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
    void inorder(TreeNode *curr, vector<int> &v){
        if(!curr)   return;
        inorder(curr->left, v);
        v.push_back(curr->val);
        inorder(curr->right, v);
        return;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, v;
        inorder(root1, v1);
        inorder(root2, v2);
        int c1= 0, c2= 0, n1= v1.size(), n2= v2.size();
        while(c1<n1  &&  c2<n2){
            if(v1[c1]<v2[c2]){
                v.push_back(v1[c1]);
                c1++;
            }
            else{
                v.push_back(v2[c2]);
                c2++;
            }
        }
        while(c1<n1){
            v.push_back(v1[c1]);
            c1++;
        }
        while(c2<n2){
            v.push_back(v2[c2]);
            c2++;
        }
        return v;
    }
};