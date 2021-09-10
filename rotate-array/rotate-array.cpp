class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size(), temp;
        vector<int> curr(n, 0);
        for(int i=0; i<n; i++){
            temp= (i+k)%n;
            curr[temp]= nums[i];
        }
        nums= curr;
    }
};