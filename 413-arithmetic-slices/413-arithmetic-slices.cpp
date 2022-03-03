class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() < 3) return 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n - 1; i++){
            if(nums[i] - nums[ i- 1] == nums[i + 1] - nums[i]){
                dp[i] = (dp[i - 1] == 0)? 1 : (dp[i - 1] + (dp[i - 1] - dp[i - 2]) + 1);
            }
        }
        if(nums[n - 1] - nums[n - 2] == nums[n-2] - nums[n-3]) dp[n - 1] = dp[n - 2];
        int ans=0;
        for(int i = 1; i < n - 1; i++){
            if(dp[i+1] == 0) ans += dp[i];
        }
        ans+= dp[n - 1];
        return ans;
    }
};