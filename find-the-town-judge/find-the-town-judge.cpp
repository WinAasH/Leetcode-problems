class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> v(n+1, 0);
        unordered_set<int> st;
        for(int i=0; i<trust.size(); i++){
            v[trust[i][1]]++;
            st.insert(trust[i][0]);
        }
        for(int i=0; i<=n; i++){
            if(v[i]==n-1  &&  st.find(i)==st.end()){
                return i;
            }
        }
        return -1;
    }
};