class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string curr= "";
        bool flag= false, first= true;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '  &&  flag){
                if(first){
                    v.push_back(curr);
                    flag= false;
                    first= false;
                    curr= "";
                    continue;
                }
                curr+= " ";
                v.push_back(curr);
                curr= "";
                flag= false;
                continue;
            }
            else if(s[i]!=' '){
                flag= true;
                curr+= s[i];   
            }
        }
        curr+= " ";
        v.push_back(curr);
        reverse(v.begin(), v.end());
        string result= "";
        for(auto it: v){
            result+= it;
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