/*
class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int j=0;        
        if(s[0]!=p[0]  &&  p[0]!='.')
        {
            if(p[1]=='*')
            {
                j++;
            }
            j++;
        }
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==p[j])
            {
                j++;
            }
            else if(p[j]=='.')
            {
                j++;
            }
            else if(p[j]=='*')
            {
                if(j>0)
                {
                    while(i<s.size()  &&  (s[i]==p[j-1]  ||  p[j-1]=='.'))
                    {
                        i++;
                    }
                    j++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
*/


class Solution {
public:
    
    // Make pattern into single-character format.
    // *   - match any sequence of characters
    // A-Z - match zero or more of corresponding lower case characters
    // .   - match any single charaters
    // a-z - match corresponding character
    string parsePattern(string p) {
        string ret;
        for (auto c: p) {
            if (c == '*') {
                if (ret.back() == '.') {
                    ret.back() = '*';
                } else {
                    ret.back() = toupper(ret.back());
                }
            } else {
                ret.push_back(c);
            }
        }
        return ret;
    }
    
    bool isMatch(string s, string p) {
        
        p = parsePattern(p);
        vector<vector<bool>> dp(p.length()+1, vector<bool>(s.length()+1, false));
        
        dp[0][0] = true; // An empty pattern matches an empty string.
        
        // first column
        for (int i = 1; i < dp.size(); ++i) {
            if (p[i-1] == '*' || p[i-1] >= 'A' & p[i-1] <= 'Z') {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = false;
            }
        }
        
        // rest of the dp table
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp.front().size(); ++j) {
                if (p[i-1] == '*') {
                    if (dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]) {
                      dp[i][j] = true;
                    }  
                } else if (p[i-1] == '.') {
                    if (dp[i-1][j-1] == true) {
                        dp[i][j] = true;
                    }
                } else if (p[i-1] >= 'A' && p[i-1] <= 'Z') {
                    if (dp[i-1][j] || tolower(p[i-1]) == s[j-1] && (dp[i-1][j-1] || dp[i][j-1])) {
                        dp[i][j] = true;
                    }
                } else {
                    if (p[i-1] == s[j-1] && dp[i-1][j-1] == true) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[dp.size()-1][dp.front().size()-1];
        
    }
};