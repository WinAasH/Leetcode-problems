class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0]==b[0])    return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans= 0, maxRange= -1;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][1]>maxRange){
                ans++;
                maxRange= intervals[i][1];
            }
        }
        return ans;
    }
};