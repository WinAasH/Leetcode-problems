class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        vector<pair<int,int>>v;
        for(auto i:mp) v.push_back({i.second,i.first});
        sort(v.begin(),v.end());
        vector<int>res;
        int n=v.size()-1;
        while(k--){
            res.push_back(v[n--].second);
        }
        return res;
    }
};