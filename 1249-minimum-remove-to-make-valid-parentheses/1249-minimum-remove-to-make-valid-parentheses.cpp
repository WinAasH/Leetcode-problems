class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        
        for(int i=0; i<s.length(); i++){
            if(!st.empty() and st.top().first=='(' and s[i]==')'){
                st.pop();
            } else if(s[i]==')' or s[i]=='(') {
                st.push({s[i], i});
            }
        }
        
        int mask[s.length()];
        for(int i=0; i<s.length(); i++){
            mask[i] = 1;
        }
        
        while(!st.empty()){
            int idx = st.top().second;
            mask[idx] = 0;
            st.pop();
        }
        
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(mask[i]){
                ans += s[i];
            }
        }
        return ans;
    }
};