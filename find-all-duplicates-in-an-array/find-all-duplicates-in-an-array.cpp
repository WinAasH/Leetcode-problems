class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        for(int i=0; i<n; i++){
            int ind= abs(nums[i])-1;
            if(nums[ind]<0){
                ans.push_back(abs(nums[i]));
            }
            nums[ind]*= nums[ind]>0? -1: 1;
        }
        return ans;
    }
};