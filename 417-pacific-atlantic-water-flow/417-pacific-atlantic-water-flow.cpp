class Solution {
private:
    void dfs(vector<vector<bool>> &v, vector<vector<int>> &heights, int r, int c, int prevHeight){
        if(r>= heights.size()  ||  c>=heights[0].size()  ||  r<0  ||  c<0  ||  prevHeight>heights[r][c]  ||  v[r][c])    return;
        v[r][c]= true;
        dfs(v, heights, r+1, c, heights[r][c]);
        dfs(v, heights, r-1, c, heights[r][c]);
        dfs(v, heights, r, c+1, heights[r][c]);
        dfs(v, heights, r, c-1, heights[r][c]);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row= heights.size(), column= heights[0].size();
        vector<vector<int>> ans;
        if(row==0  ||  column==0)   return ans;
        vector<vector<bool>> pacific, atlantic;
        for(int i=0; i<row; i++){
            vector<bool> temp;
            for(int j=0; j<column; j++){
                temp.push_back(false);
            }
            pacific.push_back(temp);
            atlantic.push_back(temp);
        }
        for(int i=0; i<row; i++){
            dfs(pacific, heights, i, 0, INT_MIN);
            dfs(atlantic, heights, i, column-1, INT_MIN);
        }
        for(int j=0; j<column; j++){
            dfs(atlantic, heights, row-1, j, INT_MIN);
            dfs(pacific, heights, 0, j, INT_MIN);
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(pacific[i][j]  &&  atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};