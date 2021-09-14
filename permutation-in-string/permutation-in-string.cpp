class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1= s1.length(), len2= s2.length();
        if(len1>len2){
            return false;
        }
        
        map<int, int> mp1;
        for(int i=0; i<26; i++){
            mp1[i];
        }
        for(int i=0; i<len1; i++){
            mp1[s1[i]-'a']++;
        }
        
        map<int, int> mp2;
        for(int i=0; i<26; i++){
            mp2[i];
        }
        for(int i=0; i<len1; i++){
            mp2[s2[i]-'a']++;
        }
        if(mp1==mp2){
            return true;
        }
        
        for(int i=len1; i<len2; i++){
            mp2[s2[i-len1]- 'a']--;
            mp2[s2[i]- 'a']++;
            if(mp1==mp2){
                return true;
            }
        }
        return false;
    }
};