class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currRow= 0, currCol= matrix[0].size() -1, row= matrix.size(), col= matrix[0].size();
        while(currRow<row  &&  currCol>=0){
            if(matrix[currRow][currCol]==target){
                return true;
            }
            else if(matrix[currRow][currCol]<target){
                currRow++;
            }
            else{
                currCol--;
            }
        }
        return false;
    }
};