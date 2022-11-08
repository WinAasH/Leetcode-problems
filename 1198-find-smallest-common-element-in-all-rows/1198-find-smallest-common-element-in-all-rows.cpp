class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> v(10001, 0);
        int r= mat.size(), c= mat[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                v[mat[i][j]]++;
            }
        }
        for(int i=0; i<10001; i++){
            if(v[i]==r) return i;
        }
        return -1;
    }
};