class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int lenN= ransomNote.length(), lenM= magazine.length();
        if(lenN>lenM){
            return false;
        }
        
        vector<int> note(26, 0), mag(26, 0);
        
        for(int i=0; i<lenN; i++){
            note[ransomNote[i]-'a']++;
        }
        
        for(int i=0; i<lenM; i++){
            mag[magazine[i]-'a']++;
        }
        
        if(note==mag){
            return true;
        }
        
        for(int i=0; i<26; i++){
            if(mag[i]<note[i]){
                return false;
            }
        }
        
        return true;
    }
};