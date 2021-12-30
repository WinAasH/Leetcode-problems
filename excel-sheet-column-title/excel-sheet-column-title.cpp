class Solution {
public:
    string convertToTitle(int colNum) {
        string ans= "";
        while(colNum){
            int curr= colNum%26;
            if(curr==0){
                ans+= 'Z';
                colNum= (colNum/26) - 1;
            }
            else{
                ans+= (curr- 1+ 'A');
                colNum/= 26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};