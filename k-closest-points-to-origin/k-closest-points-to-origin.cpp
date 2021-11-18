class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k)
    {
        vector<vector<int>> res ;
        priority_queue<pair<int, pair<int, int>>> maxh ;
        
        for(int i=0; i<p.size(); i++)
        {
            int d = p[i][0] * p[i][0] + p[i][1] * p[i][1] ;
            maxh.push({ d, { p[i][0], p[i][1]}}) ;
            
            if(maxh.size()>k){ maxh.pop() ;}
        }
        while(!maxh.empty())
        {
            res.push_back({maxh.top().second.first, maxh.top().second.second}) ; maxh.pop() ;
        }
        
        return res ;
    }
};