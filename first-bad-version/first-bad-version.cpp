// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid, high=n, ans, low=1;
        while(low<=high){
            mid= low+(high-low)/2;
            if(isBadVersion(mid)){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};