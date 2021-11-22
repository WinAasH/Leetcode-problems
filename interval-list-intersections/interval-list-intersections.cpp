class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& L1, vector<vector<int>>& L2) {
        int n1= L1.size(), n2= L2.size();
        vector<vector<int>> ans;
        if(n1==0  ||  n2==0) return ans;
        
        int first= 0, second= 0;
        while(first<n1  &&  second<n2){
            if(L1[first][0]<=L2[second][1]  &&  L1[first][1]>=L2[second][0]){
                ans.push_back({max(L1[first][0], L2[second][0]), min(L1[first][1], L2[second][1])});
            }
            else if(L2[second][1]>=L1[first][1]  &&  L1[first][0]>=L2[second][0]){
                ans.push_back({max(L1[first][0], L2[second][0]), min(L1[first][1], L2[second][1])});
            }
            
            if(L1[first][1]>L2[second][1]) second++;
            else first++;
        }
        
        return ans;
    }
};