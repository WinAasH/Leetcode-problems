class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n= nums.size();
        
        for(int i=0; i<n-1  &&  nums[i]<=0; i++){
            if(i>0  &&  nums[i]==nums[i-1]) continue;
            
            int low=i+1, high=n-1;
            
            while(low<high){
                int temp= nums[i]+nums[low]+nums[high];
                if(temp==0){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    while(low<high  &&  nums[low]==nums[low-1]) low++;
                    high--;
                    while(low<high  &&  nums[high]==nums[high+1]) high--;
                }
                else if(temp<0){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        
        return ans;
    }
};