class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        map<int, int> mp;
        int n= changed.size();
        vector<int> ans;
        if(n%2) return {};
        for(int i: changed) mp[i]++;
        for(int i=0; i<n; i++){
            if(!mp[changed[i]]) continue;
            if(!mp[changed[i]*2])   return {};
            mp[changed[i]]--;
            mp[changed[i]*2]--;
            ans.push_back(changed[i]);
        }
        return ans;
    }
};