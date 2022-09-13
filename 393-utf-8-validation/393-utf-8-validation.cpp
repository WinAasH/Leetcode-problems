class Solution {
public:
    
    vector<int> dtob(int n){
        int c=128;
        vector<int> ans;
        while(c){
            ans.push_back(n/c);
            n=n%c;
            c/=2;
        }
        for(auto i:ans) cout<<i;
        cout<<endl;
        return ans;
    }
    
    int calones(vector<int> v){
        int ans=0;
        bool flag=1;
        int i=0;
        while(flag&&i<v.size()){
            if(v[i]==1){
                ans++;
            }
            else{
                flag=0;
            }
            i++;
        }
        return ans;
    }
    
    bool validUtf8(vector<int>& data) {
        vector<vector<int>> bdata;
        for(auto i:data){
            bdata.push_back(dtob(i));;
        }
        vector<int> ones;
        for(auto i:bdata){
            ones.push_back(calones(i));
        }
        int temp=ones[0];
        if(temp==1) return false;
        if(temp>4) return false;;
        temp--;
        bool ans=true;
        for(int i=1;i<ones.size();i++){
            int curr=ones[i];
            if(curr>4) return false;
            if(temp>=1){
                if(curr!=1){
                    return false;
                }
            }
            else{
                if(curr==1){
                    return false;
                }
                temp=curr;
                if(temp>4) temp=4;
                    
            }
            temp--;
        }
        if(temp>=1) return false;
        return true;
    }
};