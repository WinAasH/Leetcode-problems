class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int low=0, high= n-1;
        while(low<high){
            int curr= numbers[low]+numbers[high];
            if(curr== target){
                return {low+1, high+1};
            }
            else if(curr< target){
                low++;
            }
            else{
                high--;
            }
        }
        return {-1};
    }
};