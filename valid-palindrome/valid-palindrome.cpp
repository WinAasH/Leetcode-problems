class Solution {
private:
    string Purify(string s){
        string ans= "";
        for(char ch: s){
            if(isalnum(ch)) ans+= ch;
        }
        return ans;
    }
    
    string lowercase(string s){
        string ans= "";
        for(char ch: s){
            char curr= tolower(ch);
            ans+= curr;
        }
        return ans;
    }
    
    bool isPal(string s){
        int l=0, h=s.length()-1;
        while(l<h){
            if(s[l]!=s[h]) return 0;
            l++;
            h--;
        }
        return 1;
    }
    
public:
    bool isPalindrome(string s) {
        string str= Purify(s);
        string smallS= lowercase(str);
        if(isPal(smallS)) return 1;
        return 0;
    }
};