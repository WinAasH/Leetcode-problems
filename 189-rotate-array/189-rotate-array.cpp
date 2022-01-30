class Solution {
private:
    void reverse(vector<int> &nums, int start, int end){
        while(start<end){
            int temp= nums[start];
            nums[start]= nums[end];
            nums[end]= temp;
            start++;
            end--;
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        int K= k%n;
        reverse(nums, 0, n-K-1);
        reverse(nums, n-K, n-1);
        reverse(nums, 0, n-1);
    }
};