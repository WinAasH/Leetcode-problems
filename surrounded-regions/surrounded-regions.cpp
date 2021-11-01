class Solution {
private:
    void change(vector<vector<char>> &board, int row, int col, char ch, vector<vector<int>> &vis){
        if(row<0  ||  col<0  ||  row>=board.size()  ||  col>=board[0].size()  ||  board[row][col]=='X'  ||  vis[row][col]==1){
            return ;
        }
        vis[row][col]=1;
        board[row][col]= ch;
        change(board, row+1, col, ch, vis);
        change(board, row-1, col, ch, vis);
        change(board, row, col+1, ch, vis);
        change(board, row, col-1, ch, vis);
        return;
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int row= board.size(), col= board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for(int i=0; i<row; i++){
            if(visited[i][0]==0  &&  board[i][0]=='O'){
                change(board, i, 0, 'Y', visited);
            }
            if(visited[i][col-1]==0  &&  board[i][col-1]=='O'){
                change(board, i, col-1, 'Y', visited);
            }
        }
        
        for(int i=0; i<col; i++){
            if(visited[0][i]==0  &&  board[0][i]=='O'){
                change(board, 0, i, 'Y', visited);
            }
            if(visited[row-1][i]==0  &&  board[row-1][i]=='O'){
                change(board, row-1, i, 'Y', visited);
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O'){
                    board[i][j]= 'X';
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='Y'){
                    board[i][j]= 'O';
                }
            }
        }
    }
};