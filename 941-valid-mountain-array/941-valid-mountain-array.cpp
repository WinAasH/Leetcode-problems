class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n= arr.size();
        if(n<=2)    return false;
        if(arr[0]>=arr[1])   return false;
        bool rise= true;
        for(int i=2; i<n; i++){
            if(rise  &&  arr[i-1]>=arr[i]) rise= false;
            if(!rise  &&  arr[i-1]<=arr[i]) return false;
        }
        return rise? false: true;
    }
};