class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                if(s[i]=='('  ||  s[i]=='{'  ||  s[i]=='['){
                    st.push(s[i]);
                }
                else{
                    return false;
                }
            }
            else if((s[i]==']'  &&  st.top()=='[')  ||  (s[i]=='}'  &&  st.top()=='{')  ||  (s[i]==')'  &&  st.top()=='(')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        return (st.empty()? true: false);
    }
};