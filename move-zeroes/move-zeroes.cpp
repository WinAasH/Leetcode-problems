class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                int j= i;
                int curr= nums[i];
                while(j+1<n  &&  nums[j]==0){
                    j++;
                }
                nums[i]= nums[j];
                nums[j]= curr;
            }
        }
    }
};