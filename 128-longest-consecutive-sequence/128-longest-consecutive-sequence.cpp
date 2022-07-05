class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int count= 0, ans= 0;
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]-1)==st.end()){
                count++;
                int j= 1;
                while(st.find(nums[i]+j)!=st.end()){
                    j++;
                    count++;
                }
                ans= max(count, ans);
                count= 0;
            }
        }
        return ans;
    }
};