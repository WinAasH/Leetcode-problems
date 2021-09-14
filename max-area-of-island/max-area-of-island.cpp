class Solution {
private:
    int countArea(vector<vector<int>> &v, int r, int c, int row, int column){
        if(r<0  ||  r>=row  ||  c<0  ||  c>=column  ||  !v[r][c]){
            return 0;
        }
        v[r][c]= 0;
        return (1+ countArea(v, r+1, c, row, column)+ countArea(v, r-1, c, row, column)+ countArea(v, r, c+1, row, column)+ countArea(v, r, c-1, row, column));
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row= grid.size(), column= grid[0].size();
        int maxArea= 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(grid[i][j]){
                    maxArea= max(countArea(grid, i, j, row, column), maxArea);
                }
            }
        }
        return maxArea;
    }
};