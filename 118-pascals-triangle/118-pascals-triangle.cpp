class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        int count= 0;
        for(int i=0; i<numRows; i++){
            count++;
            vector<int> temp(count, 1);
            for(int j=1; j<temp.size()-1; j++){
                temp[j]= prev[j-1]+ prev[j];
            }
            prev= temp;
            ans.push_back(temp);
        }
        return ans;
    }
};