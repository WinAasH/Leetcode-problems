class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans= 0, currPower= 0;
        while(n){
            int curr= 1<<currPower;
            int power= (n&1)==0?1:0;
            ans+= curr*power;
            currPower++;
            n>>= 1;
        }
        return ans;
    }
};