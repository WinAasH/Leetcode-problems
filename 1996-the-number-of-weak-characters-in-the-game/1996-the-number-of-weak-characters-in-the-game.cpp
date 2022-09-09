class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), [](vector<int> &a, vector<int> &b){
            if(a[0]==b[0])  return a[1]<b[1];
            return a[0]>b[0];
        });
        int ans= 0, maxDef= INT_MIN;
        for(int i=0; i<prop.size(); i++){
            if(prop[i][1]<maxDef)   ans++;
            maxDef= max(maxDef, prop[i][1]);
        }
        return ans;
    }
};