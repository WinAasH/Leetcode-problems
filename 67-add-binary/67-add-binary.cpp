class Solution {
public:
    string addBinary(string a, string b) {
        string ans= "";
        int lenA= a.length(), lenB= b.length();
        int x= lenA-1, y= lenB-1;
        int carry= 0;
        while(x>=0  ||  y>=0){
            int currX= x>=0?a[x]-'0': 0;
            int currY= y>=0?b[y]-'0': 0;
            int temp= currX+ currY+ carry;
            carry= temp/2;
            int tempVal= temp%2;
            ans= to_string(tempVal)+ ans;
            x--;
            y--;
        }
        if(carry==1)    ans= '1'+ ans;
        return ans;
    }
};