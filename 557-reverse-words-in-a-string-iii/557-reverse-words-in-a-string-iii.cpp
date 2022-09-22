class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int len= s.length();
        string temp= "";
        for(int i=0; i<len; i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp= "";
            }
            else{
                temp+= s[i];
            }
        }
        v.push_back(temp);
        
        vector<string> vRev;
        for(string str: v){
            reverse(str.begin(), str.end());
            vRev.push_back(str);
        }
        
        int revLen= vRev.size();
        int count=0;
        string ans= "";
        for(string str: vRev){
            if(count==revLen-1){
                ans+=str;
            }
            else{
                ans+= str+' ';
                count++;
            }
        }
        
        return ans;
    }
};