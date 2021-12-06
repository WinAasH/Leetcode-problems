class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0, even=0;
        for(int i: position){
            if(i%2) odd++;
            else even++;
        }
        return min(even, odd);
    }
};