class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len= flowerbed.size();
        for(int i=0; i<len  &&  n>0; i++){
            if(flowerbed[i]==0){
                int prev= (i==0)? 0: flowerbed[i-1];
                int next= (i==len-1)? 0: flowerbed[i+1];
                if(prev==0  &&  next==0){
                    n--;
                    flowerbed[i]= 1;
                }
            }
        }
        return n==0;
    }
};