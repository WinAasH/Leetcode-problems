class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        int count= 0, ans= 0, n= arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        priority_queue<int> pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        while(count<n/2){
            count+= pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};