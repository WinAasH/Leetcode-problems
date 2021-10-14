class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0, len= s.length(), start=0, end=0;
        if(len==0  ||  len==1){
            return len;
        }
        
        map<char, int> mp;
        
        while(end<len){
            if(mp.find(s[end])==mp.end()){
                mp[s[end]]= end;
                end++;
            }
            else{
                ans= max(ans, end-start);
                start= mp[s[end]]+1;
                end= start;
                mp.clear();
                mp[s[end]]= end;
                end++;
            }
        }
        
        ans= max(ans, end-start);
        
        return ans;
    }
};