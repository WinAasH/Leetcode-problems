class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tempNums= nums;
        sort(nums.begin(), nums.end());
        int start=0, end=nums.size()-1;
        while(start<end){
            if(nums[start]+nums[end]== target){
                break;
            }
            else if(nums[start]+nums[end] < target){
                start++;
            }
            else{
                end--;
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[start]==tempNums[i]){
                start= i;
                break;
            }
        }
        
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[end]==tempNums[i]){
                end= i;
                break;
            }
        }
        return {start, end};
    }
};