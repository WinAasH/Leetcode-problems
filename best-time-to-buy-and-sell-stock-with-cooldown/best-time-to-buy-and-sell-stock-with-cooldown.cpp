class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n<2){
            return 0;
        }
        
        vector<int> profit(n);
        vector<int> buy(n);
        
        buy[0]= -prices[0];
        buy[1]= -min(prices[0], prices[1]);
        
        profit[0]= 0;
        profit[1]= max(0, buy[0]+prices[1]);
        
        for(int i=2; i<n; i++){
            buy[i]= max(buy[i-1], profit[i-2]-prices[i]);
            profit[i]= max(profit[i-1], buy[i-1]+prices[i]);
        }
        
        return profit[n-1];
    }
};