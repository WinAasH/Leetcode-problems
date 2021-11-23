class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        
        int n= nums.size();
        int prod= 1, ans= 0, left= 0, right= 0;
        
        while(right<n){
            prod*= nums[right];
            
            while(left<right  &&  prod>=k){
                prod/= nums[left];
                left++;
            }
            
            if(prod<k){
                ans+= right-left+1;
            }
            right++;
        }
        
        return ans;
    }
};