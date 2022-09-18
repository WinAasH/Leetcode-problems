class Solution {
private:
    int max(int a, int b){
        return a>b?a:b;
    }
public:
    int trap(vector<int>& height) {
        long long n= height.size();
        vector<long long> l(n, INT_MIN), r(n, INT_MIN);
        l[0]= height[0];
        r[n-1]= height[n-1];
        for(int i=1; i<n; i++){
            l[i]= max(l[i-1], height[i]);
        }
        for(int i=0; i<n; i++){
            cout<< l[i]<< " ";
        }
        cout<< "\n";
        for(int i=n-2; i>=0; i--){
            r[i]= max(r[i+1], height[i]);
        }
        for(int i=0; i<n; i++){
            cout<< r[i]<< " ";
        }
        cout<< "\n";
        long long ans= 0;
        for(int i=1; i<n-1; i++){
            int temp= min(l[i], r[i]);
            cout<< temp<< " ";
            ans+= temp-height[i];
        }
        return ans;
    }
};