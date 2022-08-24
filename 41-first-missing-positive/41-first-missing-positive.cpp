class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int l=arr.size();
        for(int i=0;i<l;i++){
            if(arr[i]>=l  ||  arr[i]<=0  ||  arr[i]==i  ||  arr[arr[i]]==arr[i])    continue;
            else{
                int temp=arr[arr[i]];
                arr[arr[i]]=arr[i];
                arr[i]=temp;
                i--;
            }
        }
        for(int i=1;i<l;i++)    if(arr[i]!=i)   return i;
        if(arr[0]==l) return l+1;
        return l;
    }
};