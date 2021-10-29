class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n= nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(auto it: mp){
            int sec= it.second;
            if(sec>(n/2)){
                return it.first;
            }
        }
        
        return 0;
    }
};