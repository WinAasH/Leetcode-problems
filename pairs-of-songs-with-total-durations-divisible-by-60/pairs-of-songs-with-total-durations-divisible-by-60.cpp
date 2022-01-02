class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans= 0;
        unordered_map<int, int> mp;
        for(int i: time) mp[i%60]++;
        for(int i=1; i<30; i++) ans+= mp[i]*mp[60-i];
        if(mp[0]>0) ans+= mp[0]*(mp[0]-1)/2;
        if(mp[30]>0) ans+= mp[30]*(mp[30]-1)/2;
        return ans;
    }
};