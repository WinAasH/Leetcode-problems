class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans= nums[0];
        for(int i=0; i<nums.size(); i++){
            ans= max(ans, nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==ans){
                ans= i; 
                break;
            }
        }
        return ans;
    }
};