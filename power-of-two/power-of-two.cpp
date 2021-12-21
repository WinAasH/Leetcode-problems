class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        long long temp= 1;
        for(int i=0; i<32; i++){
            if(temp==n) return true;
            temp<<= 1;
        }
        return false;
    }
};