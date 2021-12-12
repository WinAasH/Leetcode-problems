class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum= 0;
        for(int i: nums) sum+= i;
        if(sum%2) return false;
        vector<vector<bool>> dp(nums.size()+1, vector<bool> (sum/2 + 1, false));
        for(int i=0; i<dp.size(); i++) dp[i][0]= true;
        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[0].size(); j++){
                dp[i][j]= dp[i-1][j];
                if(j>=nums[i-1]){
                    dp[i][j]= dp[i][j]  ||  dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[nums.size()][sum/2];
    }
};