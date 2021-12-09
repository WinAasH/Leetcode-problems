class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(true){
            if(n==1) break;
            if(st.find(n)!=st.end()) return false;
            st.insert(n);
            vector<int> v;
            while(n){
                int num= n%10;
                v.push_back(num);
                n= n/10;
            }
            n= 0;
            for(int i=0; i<v.size(); i++){
                int curr= v[i]*v[i];
                n+= curr;
            }
        }
        return true;
    }
};