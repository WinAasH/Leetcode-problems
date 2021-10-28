class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n= nums.size();
        
        for(int i=0; i<n-1; i++){
            if(i>0  &&  nums[i-1]==nums[i]){
                continue;
            }
            int start= i+1, end= n-1;
            
            while(start<end){
                int Sum= nums[i]+nums[start]+nums[end];
                if(Sum==0){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    while(start<end  &&  nums[start]==nums[start-1]){
                        start++;
                    }
                    end--;
                    while(start<end  &&  nums[end]==nums[end+1]){
                        end--;
                    }
                }
                else if(Sum<0){
                    start++;
                    while(start<end  &&  nums[start]==nums[start-1]){
                        start++;
                    }
                }
                else{
                    end--;
                    while(start<end  &&  nums[end]==nums[end+1]){
                        end--;
                    }
                }
            }
        }
        
        return ans;
    }
};