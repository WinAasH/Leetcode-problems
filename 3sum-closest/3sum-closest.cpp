class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {      
        sort(nums.begin(), nums.end());
        int closeSum=INT_MAX;
        for(int i=0; i<(nums.size()-1)  &&  closeSum!=0; i++)
        {
            int low= (i+1), high= (nums.size()-1);
            while(low<high)
            {
                int sum= nums[i]+nums[low]+nums[high];
                if(sum==target)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    if(abs(closeSum)>abs(target-sum))
                    {
                        closeSum= target-sum;
                    }
                    low++;
                }
                else
                {
                    if(abs(closeSum)>abs(target-sum))
                    {
                        closeSum= target-sum;
                    }
                    high--;
                }
            }
        }
        return target-closeSum;
    }
};