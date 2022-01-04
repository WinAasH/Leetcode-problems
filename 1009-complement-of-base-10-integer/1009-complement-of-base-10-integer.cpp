class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans= 0, currPower= 0;
        while(n){
            if((n&1)==0){
                int curr= 1<<currPower;
                ans+= curr;
            }
            currPower++;
            n>>= 1;
        }
        return ans;
    }
};