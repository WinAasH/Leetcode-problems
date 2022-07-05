class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        int ans= 0;
        for(int num: nums){
            if(!st.count(num-1)){
                int currentNum= num;
                int count= 1;
                while(st.count(currentNum+1)){
                    currentNum+= 1;
                    count+= 1;
                }
                ans= max(ans, count);
            }
        }
        return ans;
    }
};