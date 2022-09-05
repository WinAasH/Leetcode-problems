class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int ans=0,sum=0;
        for(int i=s.size()-1;i>=0;i--){
            if(sum+s[i]>=0){
                ans=ans+sum+s[i];
                sum+=s[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};