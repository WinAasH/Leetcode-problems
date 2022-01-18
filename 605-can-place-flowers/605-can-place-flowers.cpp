class Solution {
private:
    bool canPlace(vector<int> &flowerbed, int i){
        if(i>0  &&  i<flowerbed.size()-1  &&  flowerbed[i-1]!=1  &&  flowerbed[i+1]!=1) return true;
        else if(i==0  &&  flowerbed[i+1]!=1)    return true;
        else if(i==flowerbed.size()-1  &&  flowerbed[i-1]!=1)   return true;
        return false;
    }
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len= flowerbed.size(), num= 0;
        if(len==1){
            if(flowerbed[0]==0) return n<=1? true: false;
            else    return n==0? true: false;
        }
        for(int i=0; i<len; i++)  if(flowerbed[i]==0  &&  canPlace(flowerbed, i)){
            num++;
            flowerbed[i]= 1;
        }
        return num>=n? true: false;
    }
};