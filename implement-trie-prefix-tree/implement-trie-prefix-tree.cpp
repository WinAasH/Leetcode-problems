class Trie {
private:
    struct TrieNode{
        char val;
        TrieNode *child[26];
        bool isEnd;
    };
    
    TrieNode *root;
    
    TrieNode *getNode(int index){
        TrieNode *newNode= new TrieNode;
        newNode->val= 'a'+index;
        newNode->isEnd= false;
        for(int i=0; i<26; i++){
            newNode->child[i]= NULL;
        }
        return newNode;
    }
    
public:
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root= getNode('/'-'a');
    }
    
    void insert(string word) {
        TrieNode *curr= root;
        int index;
        for(char ch: word){
            index= ch-'a';
            if(curr->child[index]==NULL){
                curr->child[index]= getNode(index);
            }
            curr= curr->child[index];
        }
        curr->isEnd= true;
    }
    
    bool search(string word) {
        TrieNode *curr= root;
        int index;
        for(char ch: word){
            index= ch-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr= curr->child[index];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr= root;
        int index;
        for(char ch: prefix){
            index= ch-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr= curr->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */