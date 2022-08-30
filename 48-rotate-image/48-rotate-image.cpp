class Solution {
public:
    void rot(vector<vector<int>> &arr,int k,int n){
        int r=n-1-k;
        int length=r-k+1;
        for(int i=0;i<length-1;i++){
            int t1=arr[k][k+i];
            int t2=arr[k+i][k+length-1];
            int t3=arr[k+length-1][k+length-1-i];
            int t4=arr[k+length-1-i][k];
            arr[k][k+i]=t4;
            arr[k+i][k+length-1]=t1;
            arr[k+length-1][k+length-1-i]=t2;
            arr[k+length-1-i][k]=t3;
            
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        cout<<n;
        for(int i=0;i<n/2;i++){
            rot(matrix,i,n);
        }
    }
};          