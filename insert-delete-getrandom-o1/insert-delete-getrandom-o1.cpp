class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {
        srand((int)time(0));
    }
    
    bool insert(int val) {
        if(!mp.count(val)){
            v.push_back(val);
            mp[val]= v.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int toRemove= mp[val];
            mp.erase(val);
            if(toRemove < v.size()-1){
                int last= v[v.size()-1];
                v[toRemove]= last;
                mp[last]= toRemove;
            }
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */