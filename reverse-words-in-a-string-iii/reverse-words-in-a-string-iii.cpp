class Solution {
public:
    string reverseWords(string s) {
        vector<vector<char>> v;
        vector<char> vec;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                v.push_back(vec);
                vec.clear();
                continue;
            }
            vec.push_back(s[i]);
        }
        v.push_back(vec);
        int len= v.size();
        for(auto &it: v){
            reverse(it.begin(), it.end());
        }
        int count= 0;
        string result= "";
        for(auto it: v){
            count++;
            for(int i=0; i<it.size(); i++){
                result+= it[i];
            }
            if(len== count){
                continue;
            }
            result+= " ";
        }
        return result;
    }
};