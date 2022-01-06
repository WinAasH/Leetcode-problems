class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr= 0;
        if(trips[0][0]>capacity) return false;
        map<int, int> mp;
        for(int i=0; i<trips.size(); i++){
            mp[trips[i][1]]+= trips[i][0];
            mp[trips[i][2]]-= trips[i][0];
        }
        for(auto it= mp.begin(); it!=mp.end(); it++){
            curr+= it->second;
            if(curr>capacity)   return false;
        }
        return true;
    }
};