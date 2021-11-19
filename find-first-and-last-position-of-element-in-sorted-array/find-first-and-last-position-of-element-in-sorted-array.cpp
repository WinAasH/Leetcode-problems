class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        if(n==0){
            return {-1, -1};
        }
        
        int start= 0, end= n-1, tStart= -1, tEnd= -1;
        while(start<=end){
            int mid= start+ ((end- start)/2);
            if(nums[mid]==target){
                tStart= mid;
                end= mid-1;
                if(mid==0  ||  nums[mid-1]!=nums[mid]){
                    break;
                }
            }
            else if(nums[mid]<target){
                start= mid+1;
            }
            else{
                end= mid-1;
            }
        }
        
        start= 0;
        end= n-1;
        
        while(start<=end){
            int mid= start+ ((end- start)/2);
            if(nums[mid]==target){
                tEnd= mid;
                start= mid+1;
                if(mid==n-1  ||  nums[mid+1]!=nums[mid]){
                    break;
                }
            }
            else if(nums[mid]<target){
                start= mid+1;
            }
            else{
                end= mid-1;
            }
        }
        
        return {tStart, tEnd};
    }
};