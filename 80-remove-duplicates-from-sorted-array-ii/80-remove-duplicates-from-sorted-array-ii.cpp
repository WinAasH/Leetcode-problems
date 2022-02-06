class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start=0, end=0, count=0, n=nums.size();
        while(start<n  &&  end<n){
            while(end<n  &&  nums[start]==nums[end]){
                end++;
            }
            int temp= min(2, end-start);
            for(int i=0; i<temp; i++){
                nums[count]= nums[start];
                count++;
            }
            start= end;
        }
        return count;
    }
};