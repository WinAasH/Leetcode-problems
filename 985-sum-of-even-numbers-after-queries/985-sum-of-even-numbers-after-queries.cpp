class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int sum= 0, n= nums.size(), qlen= q.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                sum+= nums[i];
            }
        }
        for(int i=0; i<qlen; i++){
            if(nums[q[i][1]]%2==0){
                sum-= nums[q[i][1]];
                nums[q[i][1]]+= q[i][0];
                if(nums[q[i][1]]%2==0){
                    sum+= nums[q[i][1]];
                }
            }
            else{
                nums[q[i][1]]+= q[i][0];
                if(nums[q[i][1]]%2==0){
                    sum+= nums[q[i][1]];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};