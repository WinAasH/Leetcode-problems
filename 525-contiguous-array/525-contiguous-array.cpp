class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0, n= nums.size();
        map<int, int> mp;
        mp[0]= -1;
        bool change= false;
        for(int i=1; i<n; i++)  if(nums[i]!=nums[i-1])  change= true;
        for(int i=0; i<n; i++)  if(nums[i]==0)  nums[i]= -1;
        for(int i=1; i<n; i++)  nums[i]+= nums[i-1];
        for(int i=0; i<n; i++){
            if(mp.find(nums[i])!=mp.end()){
                int currAns= i-mp[nums[i]];
                ans= max(ans, currAns);
            }
            else    mp[nums[i]]= i;
        }
        return change?ans: 0;
    }
};