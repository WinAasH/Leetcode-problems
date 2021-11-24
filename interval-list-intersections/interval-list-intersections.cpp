class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& L1, vector<vector<int>>& L2) {
        int len1= L1.size(), len2= L2.size();
        vector<vector<int>> ans;
        if(len1==0  ||  len2==0) return ans;
        
        int first= 0, second= 0;
        while(first<len1  &&  second<len2){
            if(L1[first][1]>=L2[second][0]  &&  L1[first][0]<=L2[second][1]){
                ans.push_back({max(L1[first][0], L2[second][0]), min(L1[first][1], L2[second][1])});
            }
            else if(L1[first][1]>=L2[second][1]  &&  L1[first][0]<=L2[second][0]){
                ans.push_back({L2[second][0], L2[second][1]});
            }
            
            if(L1[first][1]>L2[second][1]) second++;
            else first++;
        }
        
        return ans;
    }
};