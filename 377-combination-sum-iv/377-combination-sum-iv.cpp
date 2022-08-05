class Solution {
map<int, int> mp;
private:
    int helper(vector<int> &nums, int target){
        if(mp.find(target)!= mp.end())   return mp[target];
        else if(target==0)  return 1;
        else if(target<0)   return 0;
        int possibleWays= 0;
        for(int el: nums)   possibleWays+= helper(nums, target-el);
        mp[target]= possibleWays;
        return possibleWays;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return helper(nums, target);
    }
};