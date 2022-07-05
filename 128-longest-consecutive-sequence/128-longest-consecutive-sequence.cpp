class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        sort(nums.begin(), nums.end());
        int count= 1, ans= 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                ans= max(count, ans);
                count= 1;
            }
        }
        ans= max(count, ans);
        return ans;
    }
};