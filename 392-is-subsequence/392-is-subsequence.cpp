class Solution {
private:
    bool compare(string s, string t, int sL, int tL){
        if(sL==-1)   return 1;
        if(sL>tL)   return 0;
        if(s[sL]==t[tL])    return compare(s, t, sL-1, tL-1);
        else    return compare(s, t, sL, tL-1);
    }
public:
    bool isSubsequence(string s, string t) {
        if(s==""  &&  t=="")    return 1;
        if(t=="")   return 0;
        if(s=="")   return 1;
        int sLen= s.length(), tLen= t.length();
        if(sLen>tLen)   return 0;
        return compare(s, t, sLen-1, tLen-1);
    }
};