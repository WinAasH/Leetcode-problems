class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int high=n-1, low=0;
        
        while(low<high){
            int currSum= numbers[low]+numbers[high];
            
            if(currSum==target){
                return {low+1, high+1};
            }
            else if(currSum<target){
                low++;
            }
            else{
                high--;
            }
        }
        
        return {-1};
    }
};