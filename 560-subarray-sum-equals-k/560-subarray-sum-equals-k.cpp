class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sums_count;
        int sum = 0, count= 0;
        sums_count[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sums_count.find(sum - k) != sums_count.end())   count += sums_count[sum - k];
            sums_count[sum]++;
        }
        return count;
    }
};