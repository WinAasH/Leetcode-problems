class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        if(n==0){
            return -1;
        }
        if(n==1){
            return nums[0];
        }
        
        int start= 0, end= n-1, ans= -1;
        
        if(nums[start]<nums[end]){
            return nums[start];
        }
        
        while(start<=end){
            int mid= start+ ((end- start)/2);
            int low= (mid+n-1)%n;
            int high= (mid+1)%n;
            if(nums[mid]<=nums[low]  &&  nums[mid]<=nums[high]){
                ans= nums[mid];
                break;
            }
            else if(nums[mid]<=nums[end]){
                end= mid-1;
            }
            else{
                start= mid+1;
            }
        }
        
        return ans;
    }
};