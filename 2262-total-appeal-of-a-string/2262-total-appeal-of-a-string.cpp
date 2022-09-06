class Solution {
public:
    long long appealSum(string s) {
        vector<int> v(26, 0);
        long long ans= 0, curr= 0;
        for(int i=0; i<s.length(); i++){
            int prev= v[s[i]-'a'];
            v[s[i]-'a']= i+1;
            curr+= v[s[i]-'a']-prev;
            ans+= curr;
        }
        return ans;
    }
};