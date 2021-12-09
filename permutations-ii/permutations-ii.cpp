class Solution {
private:
    vector<vector<int>> ans;
    
    void makeAll(vector<int> &nums, int j){
        if(j==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=j; i<nums.size(); i++){
            swap(nums[i], nums[j]);
            makeAll(nums, j+1);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        makeAll(nums, 0);
        vector<vector<int>> res;
        set<vector<int>> s;
        for(vector<int> it: ans) s.insert(it);
        for(vector<int> it: s) res.push_back(it);
        return res;
    }
};