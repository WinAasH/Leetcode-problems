class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0)    return true;
        int row= matrix.size(), column= matrix[0].size(), r, c;
        for(int i=0; i<row; i++){
            r= i;
            c= 0;
            int val= matrix[r][c];
            while(r<row  &&  c<column){
                if(matrix[r][c]!=val)   return false;
                r++;
                c++;
            }
        }
        for(int i=1; i<column; i++){
            r= 0;
            c= i;
            int val= matrix[r][c];
            while(r<row  &&  c<column){
                if(matrix[r][c]!=val)   return false;
                r++;
                c++;
            }
        }
        return true;
    }
};