class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int mid, low=0, high=(nums.size()-1);
        if(nums[high]<target)
        {
            return high+1;
        }
        if(nums[low]>target)
        {
            return 0;
        }
        while(low<=high)
        {
            mid= (high+low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low= mid+1;
                mid= mid+1;
            }
            else
            {
                high= mid-1;
            }
        }
        return mid;
    }
};