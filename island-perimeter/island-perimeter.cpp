class Solution {
private:
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &v){
        if(i<0  ||  i>=grid.size()  ||  j<0  ||  j>=grid[0].size()  ||  grid[i][j]==0){
            return 1;
        }
        if(v[i][j]){
            return 0;
        }
        v[i][j]= true;
        return dfs(grid, i-1, j, v)+ dfs(grid, i+1, j, v)+ dfs(grid, i, j-1, v)+ dfs(grid, i, j+1, v);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size(), column= grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(grid[i][j]){
                    return dfs(grid, i, j, visited);
                }
            }
        }
        return 0;
    }
};