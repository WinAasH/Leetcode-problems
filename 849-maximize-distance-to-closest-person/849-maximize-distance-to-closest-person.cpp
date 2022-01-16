class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n= seats.size(), currDis, res= INT_MIN, l= -1, r= -1;
        vector<int> ans(n, -1), left(n, -1), right(n, -1);
        for(int i=0; i<n; i++){
            if(seats[i]==1) l= i;
            else    left[i]= l;
        }
        for(int i=n-1; i>=0; i--){
            if(seats[i]==1) r= i;
            else    right[i]= r;
        }
        for(int i=0; i<n; i++){
            if(seats[i]==0){
                int lDis= left[i]==-1? INT_MAX: i- left[i];
                int rDis= right[i]==-1? INT_MAX: right[i]-i;
                currDis= min(lDis, rDis);
                if(currDis>res) res= currDis;
            }
        }
        return res;
    }
};