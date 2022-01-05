class Solution {
private:
    bool isPal(string s){
        int start=0, end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    string substr(string s, int start, int end){
        string ans= "";
        while(start<end){
            ans+= s[start];
            start++;
        }
        return ans;
    }
    
    void check(vector<vector<string>> &ans, vector<string> curr, string s){
        if(s.length()==0){
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<s.length(); i++){
            string first= substr(s, 0, i+1);
            if(isPal(first)){
                curr.push_back(first);
                string second= substr(s, i+1, s.length());
                check(ans, curr, second);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        check(ans, temp, s);
        return ans;
    }
};