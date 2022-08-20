class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int stops=0;
        int n= stations.size();
        int curr = 0;
        while(startFuel<target)
        {
            while((curr < n) && (startFuel>=stations[curr][0]))
            {
                pq.push(stations[curr][1]);
                curr++;
            }
            if(pq.empty())
            {
                return -1;
            }
            startFuel+=pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};