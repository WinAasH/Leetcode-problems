class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string temp= "";
        for(char ch: s){
            if(ch==' '){
                v.push_back(temp);
                temp= "";
            }
            else    temp+= ch;
        }
        v.push_back(temp);
        if(v.size()!=pattern.length())  return false;
        map<char, string> mp;
        for(int i=0; i<v.size(); i++){
            if(mp.find(pattern[i])!=mp.end()){
                string curr= mp[pattern[i]];
                if(curr!=v[i])  return false;
            }
            else    mp[pattern[i]]= v[i];
        }
        map<string, char> mp2;
        for(int i=0; i<v.size(); i++){
            if(mp2.find(v[i])!=mp2.end()){
                char curr= mp2[v[i]];
                if(curr!=pattern[i])    return false;
            }
            else    mp2[v[i]]= pattern[i];
        }
        return true;
    }
};