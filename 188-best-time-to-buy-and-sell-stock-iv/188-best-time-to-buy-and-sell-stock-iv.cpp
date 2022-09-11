class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        k = k*2;
        int dp[n+1][k+1][2];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                dp[i][j][0] = -1e9;
                dp[i][j][1] = -1e9;
            }
        }
        int ans = 0;
        for(int i=0;i<=n;i++) dp[i][0][0] =0;
        // dp[0][0][1] = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=min(i,k);j++) {
                dp[i][j][0] = max(dp[i-1][j][0] , dp[i-1][j-1][1]+prices[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1] , dp[i-1][j-1][0] - prices[i-1]);
            }
        }
        for(int i=1;i<=k;i++) ans = max(ans,dp[n][i][0]);
        return ans;
    }
};