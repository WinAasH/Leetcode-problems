class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size(), col= matrix[0].size();
        int curr_row= 0, curr_col= col-1;
        while(curr_row>=0  &&  curr_row<row  &&  curr_col>=0  &&  curr_col<col){
            int curr= matrix[curr_row][curr_col];
            
            if(curr==target){
                return true;
            }
            else if(curr<target){
                curr_row++;
            }
            else{
                curr_col--;
            }
        }
        
        return false;
    }
};