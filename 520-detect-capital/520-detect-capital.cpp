class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first= false;
        int n= word.length();
        if(isupper(word[0])){
            first= true;
        }
        if(n==1){
            return true;
        }
        if(first){
            bool second= false;
            if(isupper(word[1])){
                second= true;
            }
            if(second){
                for(int i=2; i<n; i++){
                    if(islower(word[i])){
                        return false;
                    }
                }
            }
            else{
                for(int i=2; i<n; i++){
                    if(isupper(word[i])){
                        return false;
                    }
                }
            }
        }
        else{
            for(int i=1; i<n; i++){
                if(isupper(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
};