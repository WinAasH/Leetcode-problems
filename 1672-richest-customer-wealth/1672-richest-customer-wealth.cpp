class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans= 0, r= accounts.size(), c= accounts[0].size();
        for(int i=0; i<r; i++){
            int temp= 0;
            for(int j=0; j<c; j++) temp+= accounts[i][j];
            ans= max(temp, ans);
        }
        return ans;
    }
};