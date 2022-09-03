class Solution {
private:
    void makeAll(int n, int k, int currLen, int curr, vector<int> &ans){
        if(currLen==n){
            ans.push_back(curr);
            return;
        }
        int temp= curr%10;
        currLen++;
        curr*= 10;
        
        if(k==0){
            curr+= temp;
            makeAll(n, k, currLen, curr, ans);
            return;
        }
        if(temp-k>=0){
            makeAll(n, k, currLen, curr+temp-k, ans);
        }
        if(temp+k<=9){
            makeAll(n, k, currLen, curr+temp+k, ans);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<=9; i++){
            makeAll(n, k, 1, i, ans);
        }
        return ans;
    }
};