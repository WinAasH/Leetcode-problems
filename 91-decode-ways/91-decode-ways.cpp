class Solution {
public:
    // top down
    vector<int> dp;
    int numberWays(string &s, int l, int r) {
        if(dp[l] != -1) return dp[l];
        if(s[l] == '0') return 0;
        if(l >= r) return 1;
        
        int s1 = numberWays(s, l + 1, r);
        int prefix = (s[l] - '0') * 10 + (s[l + 1] - '0');
        if(prefix <= 26)
            s1 += numberWays(s, l + 2, r);
        
        return dp[l] = s1;
    }
    
    int numDecodings(string s) {
        dp.assign(s.size() + 1, -1);
        return numberWays(s, 0, s.size() - 1);
    }
};