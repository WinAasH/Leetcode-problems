class Solution {
private:
    void change(vector<vector<char>> &v, int r, int c, char ch, char ch2){
        if(r>=v.size()  ||  c>=v[0].size()  ||  r<0  ||  c<0  ||  v[r][c]!=ch2) return;
        
        v[r][c]= ch;
        change(v, r+1, c, ch, ch2);
        change(v, r-1, c, ch, ch2);
        change(v, r, c+1, ch, ch2);
        change(v, r, c-1, ch, ch2);
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int row= board.size(), col= board[0].size();
        
        for(int i=0; i<col; i++){
            if(board[0][i]=='O'){
                change(board, 0, i, 'Y', 'O');
            }
            if(board[row-1][i]=='O'){
                change(board, row-1, i, 'Y', 'O');
            }
        }
        
        for(int i=0; i<row; i++){
            if(board[i][0]=='O'){
                change(board, i, 0, 'Y', 'O');
            }
            if(board[i][col-1]=='O'){
                change(board, i, col-1, 'Y', 'O');
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O'){
                    change(board, i, j, 'X', 'O');
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='Y'){
                    change(board, i, j, 'O', 'Y');
                }
            }
        }
    }
};