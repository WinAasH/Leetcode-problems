class Solution {
private:
    void makeAll(vector<vector<int>> &res, vector<int> &nums, vector<int> &curr, int ind){
        if(ind  ==  nums.size()){
            res.push_back(curr);
            return;
        }
        
        makeAll(res, nums, curr, ind+1);
        curr.push_back(nums[ind]);
        makeAll(res, nums, curr, ind+1);
        curr.pop_back();
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        makeAll(res, nums, curr, 0);
        return res;
    }
};