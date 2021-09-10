class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        vector<int> squareNums(n, 0);
        int low=0, high=n-1, i=n-1;
        while(i>=0  &&  low<=high){
            if(abs(nums[low])<abs(nums[high])){
                squareNums[i]= nums[high]*nums[high];
                i--;
                high--;
            }
            else{
                squareNums[i]= nums[low]*nums[low];
                i--;
                low++;
            }
        }
        return squareNums;
    }
};