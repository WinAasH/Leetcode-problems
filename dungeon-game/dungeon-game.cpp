class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row= dungeon.size(), column= dungeon[0].size();
        
        vector<vector<int>> dp(row+1, vector<int>(column+1, INT_MAX));
        
        dp[row][column]= 1;
        dp[row-1][column]= 1;
        dp[row][column-1]= 1;
        
        for(int i= row-1; i>=0; i--){
            for(int j=column-1; j>=0; j--){
                int minPower= min(dp[i+1][j], dp[i][j+1])- dungeon[i][j];
                dp[i][j]= minPower<=0? 1: minPower;
            }
        }
        return dp[0][0];
    }
};