class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            temp[nums[i]-1]= 1;
        }
        
        vector<int> ans;
        for(int i=0; i<temp.size(); i++){
            if(!temp[i]){
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};