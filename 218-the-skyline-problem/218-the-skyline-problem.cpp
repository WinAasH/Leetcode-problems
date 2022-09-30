class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> walls, ans;
        for (auto b : buildings) {
            walls.push_back({b[0], -b[2]});
            walls.push_back({b[1], b[2]});
        }
        sort(walls.begin(), walls.end());
        multiset<int> leftWallHeights = {0};                // keep left wall heights sorted; dummy '0' for convenience
        int top = 0;                                        // current max height among leftWallHeights
        for (auto w : walls) {
            if (w[1] < 0) {
                leftWallHeights.insert(-1*w[1]);
            } else {                                        // it's a right wall, delete the height
                leftWallHeights.erase(leftWallHeights.find(w[1]));
            }
            
            if (*leftWallHeights.rbegin() != top) {         // mark a skyline point if top changes
                vector<int> temp;
                temp.push_back(w[0]);
                temp.push_back(top= *leftWallHeights.rbegin());
                ans.push_back(temp);
            }
        }
        
        return ans;
}
};