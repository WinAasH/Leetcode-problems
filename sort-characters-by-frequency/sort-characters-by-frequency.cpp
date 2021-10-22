class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        
        for(char ch: s){
            mp[ch]++;
        }
        
        vector<pair<char, int>> v;
        for(auto it= mp.begin(); it!=mp.end(); it++){
            v.push_back({it->first, it->second});
        }
        
        sort(v.begin(), v.end(), [](pair<char, int> &a, pair<char, int> &b){
            return a.second>b.second; 
        });
        
        string ans= "";
        for(int i=0; i<v.size(); i++){
            while(v[i].second!=0){
                ans.push_back(v[i].first);
                v[i].second--;
            }
        }
        
        return ans;
    }
};