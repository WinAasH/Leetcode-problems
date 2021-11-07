class Solution {
public:
    string multiply(string num1, string num2) {
        int len1= num1.length();
        int len2= num2.length();
        
        if(len1==0  ||  len2==0){
            return "0";
        }
        
        int num1Int= num1[0]-'0';
        int num2Int= num2[0]-'0';
        if(num1Int==0  ||  num2Int==0){
            return "0";
        }
        
        vector<int> result(len1+len2, 0);
        for(int i=len1-1; i>=0; i--){
            for(int j=len2-1; j>=0; j--){
                int product= (num1[i]-'0')*(num2[j]-'0');
                product+= result[i+j+1];
                
                result[i+j+1]= product%10;
                result[i+j]+= product/10;
            }
        }
        
        string res;
        for(int ch: result){
            if(res.size()==0  &&  ch==0){
                continue;
            }
            res.push_back(ch+48);
        }
        return res;
    }
};