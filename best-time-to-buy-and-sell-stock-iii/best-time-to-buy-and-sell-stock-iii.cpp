class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans= 0, n=prices.size();
        
        if(n<=1){
            return 0;
        }
        
        int leftMin=prices[0], rightMax=prices[n-1];
        
        vector<int> left(n);
        left[0]= 0;
        for(int i=1; i<n; i++){
            leftMin= min(leftMin, prices[i]);
            left[i]= max(prices[i]-leftMin, left[i-1]);
        }
        
        
        vector<int> right(n);
        right[n-1]= 0;
        for(int i=n-2; i>=0; i--){
            rightMax= max(rightMax, prices[i]);
            right[i]= max(rightMax-prices[i], right[i+1]);
        }
        
        for(int i=0; i<n; i++){
            ans= max(ans, left[i]+right[i]);
        }
        
        return ans;
    }
};