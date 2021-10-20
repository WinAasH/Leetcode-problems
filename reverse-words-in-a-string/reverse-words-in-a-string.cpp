class Solution {
public:
    string reverseWords(string s) {
        stack<string> v;
        string curr= "";
        for(int i=0; i<s.length(); i++){
            while(i<s.length()  &&  s[i]==' '){
                i++;
            }
            while(i<s.length()  &&  s[i]!=' '){
                curr+= s[i];
                i++;
            }
            v.push(curr);
            curr= "";
        }
        string result= "";
        while(!v.empty()){
            result+= v.top()+" ";
            v.pop();
        }
        int i=0;
        while(result[i]==' '){
            result= result.substr(i+1);
        }
        i=result.length();
        while(result[i-1]==' '){
            result= result.substr(0, i-1);
        }
        return result;
    }
};