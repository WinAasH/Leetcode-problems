class Solution {
private:
    void rev(string &s){
        int start= 0, end= s.length()-1;
        while(start<end){
            char temp= s[start];
            s[start]= s[end];
            s[end]= temp;
            start++;
            end--;
        }
    }
public:
    string reverseWords(string s) {
        vector<string> v;
        string st= "";
        for(char ch: s){
            if(ch==' '){
                v.push_back(st);
                st= "";
            }
            else{
                st+= ch;
            }
        }
        v.push_back(st);
        st= "";
        for(string &str: v){
            rev(str);
        }
        for(int i=0; i<v.size(); i++){
            if(i+1==v.size())    st= st+ v[i];
            else    st= st+ v[i]+ ' ';
        }
        return st;
    }
};