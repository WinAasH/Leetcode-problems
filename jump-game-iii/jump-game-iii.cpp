class Solution {
private:
    bool makeAll(vector<int> &arr, vector<int> &vis, int curr){
        if(curr<0  ||  curr>=arr.size()  ||  vis[curr]) return false;
        if(arr[curr]==0) return true;
        vis[curr]= 1;
        bool R= makeAll(arr, vis, curr+arr[curr]);
        bool L= makeAll(arr, vis, curr-arr[curr]);
        return R||L;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);
        bool ans= makeAll(arr, vis, start);
        return ans;
    }
};