class Solution {
private:
    int fetchStampIndex(string t, string s, int tLen, int sLen){
        for(int i=0; i<=(tLen- sLen); i++){
            int j= 0;
            int ind= i;
            bool isNonStarChar= false;
            while(j<sLen  &&  ind<tLen  &&  (t[ind]=='*'  ||  t[ind]==s[j])){
                if(t[ind]!='*') isNonStarChar= true;
                j++;
                ind++;
            }
            if(j==sLen  &&  isNonStarChar) return i;
        }
        return -1;
    }
    
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        int sLen= stamp.size();
        int tLen= target.size();
        string newtarget= "";
        vector<int> ans;
        for(int i=0; i<tLen; i++)  newtarget+= '*';
        while(newtarget!=target){
            int stampIndex= fetchStampIndex(target, stamp, tLen, sLen);
            if(stampIndex<0){
                return {};
            }
            else{
                for(int i=0; i<stamp.size(); i++){
                    target[i+stampIndex]= '*';
                }
            }
            ans.push_back(stampIndex);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};