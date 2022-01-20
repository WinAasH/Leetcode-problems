class Solution {
private:
    bool check(vector<int> &v, int val, int hours){
        vector<int> temp(v.size(), 0);
        for(int i=0; i<v.size(); i++){
            int curr= v[i]/val;
            int rem= v[i]%val;
            if(rem==0)  temp[i]= curr;
            else    temp[i]= curr+1;
        }
        int sum= 0;
        for(int i=0; i<temp.size(); i++)    sum+= temp[i];
        return sum<=hours? true: false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1, high= INT_MIN;
        for(int i=0; i<piles.size(); i++)   high= max(high, piles[i]);
        while(low<high){
            int mid= low+ (high- low)/2;
            if(check(piles, mid, h))    high= mid;
            else    low= mid+1;
        }
        return low;
    }
};