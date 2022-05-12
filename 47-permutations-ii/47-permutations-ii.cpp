class Solution {
private:
    vector<vector<int>> ans;
    
    void makeAll(vector<int> &nums, int j){
        if(j==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> st;
        
        for(int i=j; i<nums.size(); i++){
            if(st.find(nums[i])!=st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[j]);
            makeAll(nums, j+1);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        makeAll(nums, 0);
        return ans;
    }
};