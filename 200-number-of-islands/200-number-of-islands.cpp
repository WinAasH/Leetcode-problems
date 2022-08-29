class Solution {
private:
    void flipIsland(vector<vector<char>> &v, int r, int c){
        if(r<0  ||  c<0  ||  r>=v.size()  ||  c>=v[0].size()  ||  v[r][c]=='0'){
            return;
        }
        
        v[r][c]= '0';
        flipIsland(v, r+1, c);
        flipIsland(v, r-1, c);
        flipIsland(v, r, c+1);
        flipIsland(v, r, c-1);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans= 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    ans++;
                    flipIsland(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};