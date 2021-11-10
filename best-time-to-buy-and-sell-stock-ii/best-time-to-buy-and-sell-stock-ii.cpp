class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit= 0, n= prices.size();
        
        for(int i=0; i<n-1; i++){
            int buy= 0, sell= 0;
            
            while(i<n-1  &&  prices[i]>=prices[i+1]){
                i++;
            }
            buy+= prices[i];
            
            while(i<n-1  &&  prices[i]<prices[i+1]){
                i++;
            }
            sell+= prices[i];
            
            profit+= (sell-buy);
        }
        
        return profit;
    }
};