class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())  return 0;
        vector<int> vS(26, 0);
        vector<int> vT(26, 0);
        for(int i=0; i<s.length(); i++) vS[s[i]-'a']++;
        for(int i=0; i<t.length(); i++) vT[t[i]-'a']++;
        return vS==vT?true: false;
    }
};