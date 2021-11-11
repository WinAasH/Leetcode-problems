class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1= num1.length(), len2= num2.length();
        if(len1 < len2){
            return addStrings(num2, num1);
        }
        string ans= "";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int carry= 0;
        for(int i=0; i<len1; i++){
            int n1= num1[i]- '0';
            int n2= (i<len2)? num2[i]- '0': 0;
            
            int temp= n1+n2+carry;
            ans+= to_string(temp%10);
            carry= temp/10;
        }
        
        if(carry!=0){
            ans+= to_string(carry);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};