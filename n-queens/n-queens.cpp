class Solution {
private:
    bool isValid(vector<string> &board, int r, int c){
        for(int i=0; i<r; i++){
            if(board[i][c]=='Q'){
                return false;
            }
        }
        
        for(int i=0; i<c; i++){
            if(board[r][i]=='Q'){
                return false;
            }
        }
        
        int currR= r-1, currC= c-1;
        while(currR>=0  &&  currC>=0){
            if(board[currR][currC]=='Q'){
                return false;
            }
            currR--;
            currC--;
        }
        
        currR= r+1;
        currC= c-1;
        while(currR<board.size()  &&  currC>=0){
            if(board[currR][currC]=='Q'){
                return false;
            }
            currR++;
            currC--;
        }
        
        return true;
    }
    
    
    void putQ(vector<vector<string>> &res, vector<string> &board, int len, int index){
        if(index==len){
            res.push_back(board);
            return ;
        }
        
        for(int row=0; row<len; row++){
            board[row][index]= 'Q';
            if(isValid(board, row, index)){
                putQ(res, board, len, index+1);
            }
            board[row][index]= '.';
        }
    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<vector<string>> result;
        vector<string> board(n, s);
        putQ(result, board, n, 0);
        return result;
    }
};