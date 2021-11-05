class Solution {
public:
    int arrangeCoins(int n) {
        long long count= 0, coins= 0;
        for(int i=1; coins<n; i++){
            coins+= i;
            count++;
        }
        return (int)(coins==n? count: count-1);
    }
};