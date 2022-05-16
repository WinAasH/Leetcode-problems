class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r= grid.size(), c= grid[0].size();
        if(grid[0][0]  ||  grid[r-1][c-1]) return -1;
        
        queue<vector<int>>  q;
        q.push({0, 0, 1});
        vector<vector<int>> dir= {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};
        while(!q.empty()){
            int n= q.size();
            while(n--){
                vector<int> temp= q.front();
                q.pop();
                
                if(temp[0]==r-1  &&  temp[1]==c-1) return temp[2];
                
                for(vector<int> v: dir){
                    int currR= temp[0]+v[0];
                    int currC= temp[1]+v[1];
                    
                    if(currR>=0  &&  currR<r  &&  currC>=0  &&  currC<c  &&  grid[currR][currC]==0){
                        grid[currR][currC]= 1;
                        q.push({currR, currC, temp[2]+1});
                    }
                }
            }
        }
        
        return -1;
    }
};