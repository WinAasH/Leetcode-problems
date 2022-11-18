class Solution {
public:
    bool isUgly(int n) {
        if(n==0)    return false;
        string ans= "";
        while(n!=1){
            if(n%2==0){
                n/= 2;
                ans+= '2';
            }
            else if(n%3==0){
                n/= 3;
                ans+= '3';
            }
            else if(n%5==0){
                n/= 5;
                ans+= '5';
            }
            else{
                ans+= to_string(n);
                return false;
            }
        }
        return true;
    }
};