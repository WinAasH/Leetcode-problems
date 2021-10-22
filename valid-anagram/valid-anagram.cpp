class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vS(26, 0), vT(26, 0);
        
        for(int i=0; i<s.length(); i++){
            vS[s[i]-'a']++;
        }
        
        for(int i=0; i<t.length(); i++){
            vT[t[i]-'a']++;
        }
        
        return (vS==vT)? true: false;
    }
};