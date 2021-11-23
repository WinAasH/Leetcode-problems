class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int sum= 0, ans= INT_MAX, slow= 0, fast= 0;
        
        while(fast<n){
            sum+= nums[fast];
            
            while(slow<fast  &&  sum-nums[slow]>=target){
                sum-= nums[slow];
                slow++;
            }
            
            if(sum>=target){
                ans= min(ans, fast-slow+1);
            }
            fast++;
        }
        
        return ans==INT_MAX? 0: ans;
    }
};