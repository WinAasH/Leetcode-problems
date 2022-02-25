class Solution {
private:
    int findLen(string v1, int ind){
        if(v1[ind]=='.')  return 0;
        long long ans= 0;
        for(int i= ind; i<v1.length()  &&  v1[i]!='.'; i++){
            if(v1[i]=='.') break;
            int curr= v1[i]-'0';
            ans*= 10;
            ans+= curr;
        }
        return ans;
    }
public:
    int compareVersion(string version1, string version2) {
        int len1= version1.length(), len2= version2.length(), i1= 0, i2= 0;
        while(i1<len1  ||  i2<len2){
            int l1= i1<len1? findLen(version1, i1): 0;
            int l2= i2<len2? findLen(version2, i2): 0;
            if(l1>l2)   return 1;
            else if(l1<l2)  return -1;
            while(i1<len1  &&  version1[i1]!='.')    i1++;
            while(i2<len2  &&  version2[i2]!='.')    i2++;
            i1++;
            i2++;
        }
        return 0;
    }
};