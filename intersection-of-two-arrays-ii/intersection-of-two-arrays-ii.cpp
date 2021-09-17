class Solution {
private:
    vector<int> getFrequency(vector<int> &v){
        vector<int> a(1001, 0);
        for(int i=0; i<v.size(); i++){
            a[v[i]]++;
        }
        return a;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> frequency1= getFrequency(nums1);
        
        vector<int> frequency2= getFrequency(nums2);
        
        vector<int> ans;
        for(int i=0; i<frequency1.size(); i++){
            int count= min(frequency1[i], frequency2[i]);
            while(count>0){
                ans.push_back(i);
                count--;
            }
        }
        
        return ans;
    }
};