class Solution {
private:
    string realText(string str){
        string ans= "";
        stack<char> st;
        for(char ch: str){
            if(ch=='#') if(st.empty()) continue; else st.pop();
            else st.push(ch);
        }
        
        while(!st.empty()){
            char temp= st.top();
            st.pop();
            ans= temp+ ans;
        }
        
        return ans;
    }
public:
    bool backspaceCompare(string s, string t) {
        string text1= realText(s);
        string text2= realText(t);
        
        return text1==text2? true: false;
    }
};