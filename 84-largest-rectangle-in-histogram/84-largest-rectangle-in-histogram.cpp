class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> left, right;
        vector<int> l, r;
        int n= heights.size();
        left.push({-1, -1});
        right.push({-1, n});
        for(int i=0; i<n; i++){
            int curr= heights[i];
            while(!left.empty()  &&  curr<=left.top().first) left.pop();
            if(left.empty())    l.push_back(-1);
            else    l.push_back(left.top().second);
            left.push({curr, i});
        }
        for(int i=n-1; i>=0; i--){
            int curr= heights[i];
            while(!right.empty()  &&  curr<=right.top().first)   right.pop();
            if(right.empty())    r.push_back(n-1);
            else    r.push_back(right.top().second);
            right.push({curr, i});
        }
        reverse(r.begin(), r.end());
        int ans= 0;
        for(int i=0; i<n; i++){
            int width= r[i]-l[i]-1;
            int height= heights[i];
            int currAns= width*height;
            ans= max(ans, currAns);
        }
        return ans;
    }
};