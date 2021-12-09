class Solution {
private:
    set<vector<int>> res;
    
    void helper(vector<int> candidates, int remain, vector<int> s) {

        if (remain == 0) {
            if (res.find(s)==res.end()){
                res.insert(s);
            }
        } else {
            // keep track of last candidate used
            // there's no point use it again
            int prev_candidate = -1;
            while(!candidates.empty()) {
                
                if (candidates[0] <= remain && candidates[0] != prev_candidate) {

                    vector<int> new_s = s;
                    new_s.push_back(candidates[0]);
                    // update previous stored candidate
                    prev_candidate = candidates[0];
                    
                    candidates.erase(candidates.begin());
                    helper(candidates, remain-new_s.back(), new_s);
                    
                } else {
                    candidates.erase(candidates.begin());
                }
                
                
            }
        }

        
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> s;
        
        helper(candidates, target, s);
        
        vector<vector<int>> ans(res.begin(), res.end());
        
        return ans;
        
    }
};