class Solution {
public:
    vector<string> res;
    set<string> temp;
    vector<string> letterCasePermutation(string s) {
        char out[13];
        letterCasePermutation(s, out, 0, 0);
        for(auto x: temp){
            res.push_back(x);
        }
        return res;
    }
    void letterCasePermutation(string s, char *out, int i, int j){
        if(s[i]=='\0'){
            out[j]='\0';
            temp.insert(out);
            return;
        }
        out[j] = toupper(s[i]);
        letterCasePermutation(s, out, i+1, j+1);
        
        out[j] = tolower(s[i]);
        letterCasePermutation(s, out, i+1, j+1);
        
        return;
    }
};