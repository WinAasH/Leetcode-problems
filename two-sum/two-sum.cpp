class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tempAns;
        unordered_map<int, int> mp;
        int n= nums.size();
        
        for(int i=0; i<n; i++){
            int temp= target-nums[i];
            if(mp.find(temp)!=mp.end()){
                return {mp.find(temp)->second, i};
                continue;
            }
            mp[nums[i]]= i;
        }
        
        return tempAns;
    }
};