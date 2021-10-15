class Solution {
private:
    int area(vector<vector<int>> &grid, int r, int c){
        if(r<0  ||  c<0  ||  r==grid.size()  ||  c==grid[0].size()  ||  !grid[r][c]){
            return 0;
        }
        
        grid[r][c]= 0;
        return 1+ area(grid, r+1, c)+ area(grid, r-1, c)+ area(grid, r, c+1)+ area(grid, r, c-1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    int totalArea= area(grid, i, j);
                    maxArea= max(maxArea, totalArea);
                }
            }
        }
        return maxArea;
    }
};