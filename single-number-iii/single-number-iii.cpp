class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR= 0;
        for(int i: nums){
            XOR^= i;
        }
        
        int setBit= 1;
        while(!(setBit & XOR)){
            setBit<<= 1;
        }
        
        vector<int> ans(2, 0);
        for(int i: nums){
            if(setBit & i){
                ans[0]^= i;
            }
            else{
                ans[1]^= i;
            }
        }
        
        return ans;
    }
};