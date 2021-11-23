class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenP= p.length(), lenS= s.length();
        vector<int> ans;
        if(lenP>lenS) return ans;
        
        vector<int> P(26, 0);
        for(int i=0; i<lenP; i++) P[p[i]-'a']++;
        
        vector<int> S(26, 0);
        for(int i=0; i<lenP; i++) S[s[i]-'a']++;
        
        if(P==S) ans.push_back(0);
        
        for(int i=lenP; i<lenS; i++){
            S[s[i-lenP]-'a']--;
            S[s[i]-'a']++;
            
            if(S==P) ans.push_back(i-lenP+1);
        }
        
        return ans;
    }
};