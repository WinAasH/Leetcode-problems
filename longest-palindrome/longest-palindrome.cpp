class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        
        int ans= 0;
        bool oddfound= false;
        for(auto it: mp){
            if(it.second%2){
                oddfound= true;
                ans+= it.second-1;
            }
            else{
                ans+= it.second;
            }
        }
        
        if(oddfound){
            ans++;
        }
        
        return ans;
    }
};