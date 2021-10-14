class Solution {
private:
    void fill(vector<vector<int>> &img, int r, int c, int oldColor, int color, vector<vector<int>> &vis){
        if(r<0  ||  c<0  ||  r==img.size()  ||  c==img[0].size()  ||  vis[r][c]  ||  img[r][c]!=oldColor){
            return;
        }
        
        vis[r][c]= 1;
        img[r][c]= color;
        fill(img, r+1, c, oldColor, color, vis);
        fill(img, r, c+1, oldColor, color, vis);
        fill(img, r-1, c, oldColor, color, vis);
        fill(img, r, c-1, oldColor, color, vis);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n= image.size(), m= image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int oldColor= image[sr][sc];
        fill(image, sr, sc, oldColor, newColor, visited);
        return image;
    }
};