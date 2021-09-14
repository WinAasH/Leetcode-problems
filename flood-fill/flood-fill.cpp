class Solution {
private:
    void dfs(vector<vector<int>> &v, int sRow, int sColumn, int newColor, int r, int c, int s){
        if(sRow<0  ||  sRow>=r  ||  sColumn<0  ||  sColumn>=c){
            return;
        }
        if(v[sRow][sColumn]!= s){
            return;
        }
        
        v[sRow][sColumn]= newColor;
        
        dfs(v, sRow+1, sColumn, newColor, r, c, s);
        dfs(v, sRow-1, sColumn, newColor, r, c, s);
        dfs(v, sRow, sColumn+1, newColor, r, c, s);
        dfs(v, sRow, sColumn-1, newColor, r, c, s);
    }
    
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int source= image[sr][sc];
        if(newColor== source){
            return image;
        }
        
        int row= image.size();
        int column= image[0].size();
        dfs(image, sr, sc, newColor, row, column, source);
        return image;
    }
};