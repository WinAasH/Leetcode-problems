class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1(m, 0);
        for(int i=0; i<m; i++){
            temp1[i]= nums1[i];
        }
        
        if(m==0){
            nums1= nums2;
            return ;
        }
        if(n==0){
            return;
        }
        
        int count1=0, count2=0, count=0;
        while(count1<m  &&  count2<n){
            if(temp1[count1]<nums2[count2]){
                nums1[count]= temp1[count1];
                count++;
                count1++;
            }
            else{
                nums1[count]= nums2[count2];
                count++;
                count2++;
            }
        }
        
        while(count1!=m){
            nums1[count]= temp1[count1];
            count++;
            count1++;
        }
        
        while(count2!=n){
            nums1[count]= nums2[count2];
            count++;
            count2++;
        }
    }
};