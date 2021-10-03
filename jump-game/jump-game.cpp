class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len= nums.size(), maxReach=nums[0];
        
        if(len==1){
            return true;
        }
        
        int i=1;
        while(maxReach>=i){
            if(maxReach>=len-1){
                return true;
            }
            maxReach= max(maxReach, nums[i]+i);
            i++;
        }
        return false;
    }
};