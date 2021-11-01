class Solution {
private:
    void swap(int &a, int &b){
        int temp= a;
        a= b;
        b= temp;
    }
    
    void change(vector<vector<int>> &matrix, int row){
        int start= 0, end= matrix[0].size()-1;
        while(start<end){
            swap(matrix[row][start], matrix[row][end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int row= matrix.size(), col= matrix[0].size();
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0; i<row; i++){
            change(matrix, i);
        }
    }
};