class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count= 0, n= nums.size();
        for(int i=0; i<n; i++){
            int temp= i;
            int curr;
            if(nums[i]==0){
                while(temp+1<n  &&  nums[temp]==0){
                    count++;
                    temp++;
                }
                curr= nums[i];
                nums[i]= nums[temp];
                nums[temp]= curr;
            }
        }
    }
};