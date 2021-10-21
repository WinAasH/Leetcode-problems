class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row= mat.size(), col= mat[0].size();
        if(row*col != r*c){
            return mat;
        }
        
        vector<int> temp;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                temp.push_back(mat[i][j]);
            }
        }
        
        vector<vector<int>> ans(r, vector<int> (c, 0));
        int count=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[i][j]= temp[count];
                count++;
            }
        }
        
        return ans;
    }
};