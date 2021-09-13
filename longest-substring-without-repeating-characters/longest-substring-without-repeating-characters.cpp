class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans;
        for(int i=0; i<s.length(); i++){
            unordered_set<char> check;
            for(int j=i; j<s.length(); j++){
                if(check.find(s[j])!=check.end()){
                    break;
                }
                check.insert(s[j]);
            }
            int len=check.size();
            ans= max(ans, len);
        }
        return ans;
    }
};