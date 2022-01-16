class Solution {
private:
    int findClose(vector<int> &seats, int i){
        int l= i-1, r= i+1, ans= 1;
        while(l>=0  &&  r<seats.size()){
            if(seats[l]==1  ||  seats[r]==1)    break;
            l--;
            r++;
            ans++;
        }
        if(l<0){
            while(r<seats.size()){
                if(seats[r]==1) break;
                r++;
                ans++;
            }
        }
        if(r==seats.size()){
            while(l>=0){
                if(seats[l]==1) break;
                l--;
                ans++;
            }
        }
        return ans;
    }
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans= INT_MIN;
        for(int i=0; i<seats.size(); i++){
            if(seats[i]==0) ans= max(ans, findClose(seats, i));
        }
        return ans;
    }
};