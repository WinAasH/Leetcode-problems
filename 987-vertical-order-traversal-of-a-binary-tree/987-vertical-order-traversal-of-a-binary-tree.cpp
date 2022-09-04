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
bool mycompare(const pair<int, int> &a, const pair<int, int> &b)
{
    
    if (a.second == b.second)
    {
        return (a.first < b.first);
    }
    return (a.second < b.second);
}
class Solution {
public:
    void generate(map<int, vector<pair<int, int>>> &ans, TreeNode *root, int row, int h)
{
    if (root == NULL)
    {
        return;
    }
    ans[h].push_back({root->val, row});
    generate(ans, root->left, row + 1, h - 1);
    generate(ans, root->right, row + 1, h + 1);
}

// static bool mycompare(pair<int, int> &a, pair<int, int> &b)
// {
    
//     if (a.second == b.second)
//     {
//         return a.first < b.first;
//     }
//     return a.second < b.second;
// }

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, vector<pair<int, int>>> ans;
    int row = 0;
    int h = 0;
    generate(ans, root, row, h);
    //for(auto i:ans[0]) cout<<i.first<<" : "<<i.second<<endl<<" ";
    for (auto &i : ans)
    {   
        sort(i.second.begin(), i.second.end(), mycompare);
    }
    //for(auto &i:ans[0]) cout<<i.first<<" ";
    vector<vector<int>> final;
    for (auto i : ans)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            temp.push_back(j.first);
        }
        final.push_back(temp);
    }
    return final;
}};