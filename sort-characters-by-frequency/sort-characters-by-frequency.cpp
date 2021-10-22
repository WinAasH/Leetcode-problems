class Solution {
private:
    vector<string> buildBucketArray(map<char, int> mp, int maxCount){
        vector<string> ans(maxCount+1, "");
        
        for(auto it= mp.begin(); it!=mp.end(); it++){
            ans[it->second].push_back(it->first);
        }
        
        return ans;
    }
    
    string getAns(vector<string> v){
        string ans= "";
        for(int i=v.size()-1; i>=0; i--){
            int pos= 0;
            while(v[i].length()  &&  pos<v[i].length()){
                int count= i;
                while(count){
                    ans+= v[i][pos];
                    count--;
                }
                pos++;
            }
        }
        return ans;
    }
    
public:
    string frequencySort(string s) {
        int len= s.length();
        if(len==0){
            return "";
        }
        if(len==1  ||  len==2){
            return s;
        }
        
        map<char, int> mp;
        int maxCount=0;
        for(char ch: s){
            mp[ch]++;
            maxCount= max(maxCount, mp[ch]);
        }
        
        vector<string> bucketArray= buildBucketArray(mp, maxCount);
        
        return getAns(bucketArray);
    }
};