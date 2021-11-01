class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        if(rowIndex==1){
            return {1, 1};
        }
        
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1, 1});
        for(int i=2; i<=rowIndex; i++){
            vector<int> curr= ans[i-1];
            vector<int> temp;
            temp.push_back(1);
            for(int i=1; i<curr.size(); i++){
                temp.push_back(curr[i]+curr[i-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        
        return ans[ans.size()-1];
    }
};