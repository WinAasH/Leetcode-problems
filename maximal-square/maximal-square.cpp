class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int res = 0;
        int n = mat.size(),m = mat[0].size();
        int dp[n+1][m+1];
        for(int i = 0;i < n;i++){
    		for(int j = 0;j < m;j++){
    		    if(i==0 || j == 0) dp[i][j] = mat[i][j]-'0';
    		    else{
        			if(mat[i][j] == '1')
        				dp[i][j] = min(dp[i-1][j-1], 
        				            min(dp[i][j-1], dp[i-1][j])) + 1;
        			else
        				dp[i][j]=0;
    		    }
    			res = max(res, dp[i][j]);
    		}
    	}
    	
    	return res*res;
    }
};