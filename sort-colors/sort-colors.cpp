class Solution {
public:
    void sortColors(vector<int>& nums) {
        int R=0, W=0, B=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                R++;
            }
            else if(nums[i]==1){
                W++;
            }
            else{
                B++;
            }
        }
        
        int curr=0;
        while(R){
            nums[curr]= 0;
            R--;
            curr++;
        }
        while(W){
            nums[curr]= 1;
            W--;
            curr++;
        }
        while(B){
            nums[curr]= 2;
            B--;
            curr++;
        }
    }
};