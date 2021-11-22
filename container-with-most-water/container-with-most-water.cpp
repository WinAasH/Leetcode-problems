class Solution {
public:
    int maxArea(vector<int>& nums) {
        int ans= 0, start= 0, end= nums.size()-1;
        
        while(start<end){
            int temp= min(nums[start], nums[end]);
            int water= temp*(end-start);
            
            ans= max(ans, water);
            
            if(nums[start]==temp) start++;
            else end--;
        }
        
        return ans;
    }
};