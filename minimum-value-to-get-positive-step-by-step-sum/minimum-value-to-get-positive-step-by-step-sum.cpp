class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0]<=0? -1*nums[0]+ 1: 1;
        }
        
        for(int i=1; i<n; i++){
            nums[i]+= nums[i-1];
        }
        
        int ans= nums[0];
        for(int i=1; i<n; i++){
            ans= min(nums[i], ans);
        }
        
        return ans<=0? -1*ans+ 1: 1;
    }
};