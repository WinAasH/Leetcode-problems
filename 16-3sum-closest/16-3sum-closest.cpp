class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(), ans=nums[0]+nums[1]+nums[2];
        for(int i=0; i<n; i++){
            int a=nums[i], k=n-1, j=i+1;
            while(j<k){
                int temp=a+nums[j]+nums[k];
                if(abs(temp-target)<abs(ans-target)) ans=temp;
                if(temp==target) return target;
                if(target>temp) j++;
                else    k--;
            }
        }
        return ans;
    }
};