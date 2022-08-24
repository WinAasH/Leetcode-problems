class Solution {
public:
    void swap(vector<int> &arr,int a,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    int firstMissingPositive(vector<int>& arr) {
        int l=arr.size();
        for(int i=0;i<l;i++){
            // for(int i=0;i<l;i++){
            //     cout<<arr[i]<<" ";
            // }
            // cout<<endl;
            if(arr[i]>=l||arr[i]<=0||arr[i]==i){
                
            }
            else{
                if(arr[arr[i]]==arr[i]) continue;
                // cout<<"here";
                swap(arr,i,arr[i]);
                i--;
            }
        }
        
        for(int i=1;i<l;i++){
            if(arr[i]!=i){
                return i;
            }
        }
        if(arr[0]==l) return l+1;
        return l;
    }
};