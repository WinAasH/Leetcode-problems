class Trie {
private:
    bool check(string s1, string s2){
        int len1= s1.length(), len2= s2.length();
        if(len2>len1){
            return false;
        }
        int i=0;
        while(s1[i]==s2[i]){
            i++;
            if(i>=len2){
                return true;
            }
        }
        return false;
    }
public:
    vector<string> s;
    
    void insert(string word) {
        s.push_back(word);
    }
    
    bool search(string word) {
        for(string st: s){
            if(st==word){
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for(string st: s){
            if(check(st, prefix)){
                return true;
            }
        }
        return false;
    }
};

/*
 *
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */