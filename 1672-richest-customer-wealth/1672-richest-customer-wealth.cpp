class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans= 0;
        for(int i=0; i<accounts.size(); i++)    for(int j=1; j<accounts[0].size(); j++) accounts[i][j]+= accounts[i][j-1];
        for(int i=0; i<accounts.size(); i++)    ans= max(ans, accounts[i][accounts[0].size()-1]);
        return ans;
    }
};