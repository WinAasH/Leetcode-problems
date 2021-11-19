class Solution {
public:
    int hammingDistance(int x, int y) {
        int count= 0;
        for(int i=31; i>=0; i--){
            int a= (x>>i)&1;
            int b= (y>>i)&1;
            if(a^b) count++;
        }
        
        return count;
    }
};