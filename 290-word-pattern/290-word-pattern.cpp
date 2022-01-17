class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.length()==0  ||  s.length()==0){
            return false;
        }
        
        vector<string> str;
        string temp= "";
        for(char ch: s){
            if(ch==' '){
                str.push_back(temp);
                temp= "";
            }
            else{
                temp+= ch;
            }
        }
        str.push_back(temp);
        
        if(pattern.length()!=str.size()){
            return false;
        }
        
        map<char, string> charMap;
        map<string, char> stringMap;
        for(int i=0; i<str.size(); i++){
            if(charMap.find(pattern[i])==charMap.end()){
                charMap[pattern[i]]= str[i];
            }
            else{
                if(charMap[pattern[i]]!=str[i]){
                    return false;
                }
            }
            
            if(stringMap.find(str[i])==stringMap.end()){
                stringMap[str[i]]= pattern[i];
            }
            else{
                if(stringMap[str[i]]!=pattern[i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};