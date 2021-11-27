class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n, 1), leftPrefix(n, 1), rightPrefix(n, 1);
        int leftPrefixProduct= 1;
        for(int i=0; i<n; i++){
            leftPrefixProduct= leftPrefixProduct*nums[i];
            leftPrefix[i]= leftPrefixProduct;
        }
        int rightPrefixProduct= 1;
        
        for(int i=n-1; i>=0; i--){
            rightPrefixProduct= rightPrefixProduct*nums[i];
            rightPrefix[i]= rightPrefixProduct;
        }
        
        for(int i=0; i<n; i++){
            int tempL= i>0? leftPrefix[i-1]: 1;
            int tempR= i<n-1? rightPrefix[i+1]: 1;
            ans[i]= tempL*tempR;
        }
        
        return ans;
    }
};