class Solution {
private:
    bool check(vector<vector<char>> &board, int r, int c, int currR, int currC, int ind, string word, vector<vector<int>> &visited){
        if(ind == word.length()){
            return true;
        }
        
        if(currR<0  ||  currC<0  ||  currR>=r  ||  currC>=c  ||  visited[currR][currC]== 1){
            return false;
        }
        
        if(word[ind] != board[currR][currC]){
            return false;
        }
        
        visited[currR][currC]= 1;
            
        if(check(board, r, c, currR+1, currC, ind+1, word, visited)  ||  check(board, r, c, currR-1, currC, ind+1, word, visited)  ||  check(board, r, c, currR, currC-1, ind+1, word, visited)  ||  check(board, r, c, currR, currC+1, ind+1, word, visited)){
            return true;
        }
        
        visited[currR][currC]= 0;
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows= board.size(), columns= board[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(word[0]==board[i][j]){
                    vector<vector<int>> visited(rows, vector<int>(columns, 0));
                    if(check(board, rows, columns, i, j, 0, word, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};