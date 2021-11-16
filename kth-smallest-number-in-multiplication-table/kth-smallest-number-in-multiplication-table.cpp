class Solution {
private:
    int count(int mid, int r, int c){
        int cnt= 0;
        for(int i=1; i<=r; i++){
            cnt+= min(mid/i, c);
        }
        return cnt;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low=0, high= m*n;
        
        while(low<high){
            int mid= low+ (high- low)/2;
            int capacity= count(mid, m, n);
            if(capacity >= k){
                high= mid;
            }
            else{
                low= mid+1;
            }
        }
        
        return low;
    }
};