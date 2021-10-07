class Solution {
public:
    
    bool dfs(vector<vector<char>>& board,string word,int x,int y,int index)
    {
        if (index==word.length())  return true;
        if (x>=board.size()  || x<0 || y<0 || y>=board[0].size() || board[x][y]=='#' || board[x][y]!=word[index])  return false;
        
        char c= board[x][y];
        board[x][y]='#';
        
        bool a= (dfs(board,word,x+1,y,index+1) || dfs(board,word,x-1,y,index+1) || dfs(board,word,x,y+1,index+1) || dfs(board,word,x,y-1,index+1));
                 
                 board[x][y]=c;
                 return a;
        
    }
                 
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                if (board[i][j]==word[0])
                {
                    if (dfs(board,word,i,j,0))   return true;
                }
            }
        }
        return false;
        
    }
};