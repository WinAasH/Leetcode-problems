class Solution {
private:
    void makeAll(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int ind){
        if(ind==nums.size()) res.push_back(curr);
        else{
            makeAll(nums, res, curr, ind+1);
            curr.push_back(nums[ind]);
            makeAll(nums, res, curr, ind+1);
            curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> tempRes;
        vector<int> curr;
        makeAll(nums, tempRes, curr, 0);
        for(vector<int> &it: tempRes)    sort(it.begin(), it.end());
        set<vector<int>> st;
        for(vector<int> it: tempRes)    st.insert(it);
        vector<vector<int>> res;
        for(vector<int> it: st) res.push_back(it);
        return res;
    }
};