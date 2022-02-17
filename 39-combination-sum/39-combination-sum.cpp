class Solution {
private:
    void build(vector<vector<int>> &ans, vector<int> &curr, vector<int> &v, int index, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        else if(index>=v.size()){
            return;
        }
        else if(v[index]>target){
            return;
        }
        int temp= v[index];
        curr.push_back(temp);
        build(ans, curr, v, index, target-temp);
        curr.pop_back();
        build(ans, curr, v, index+1, target);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        build(ans, curr, candidates, 0, target);
        return ans;
    }
};