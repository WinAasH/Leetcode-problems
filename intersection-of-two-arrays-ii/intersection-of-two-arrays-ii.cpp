class Solution {
private:
    vector<int> getFrequency(vector<int> &v){
        vector<int> res(1001, 0);
        for(int i=0; i<v.size(); i++){
            res[v[i]]++;
        }
        return res;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> f1= getFrequency(nums1);
        vector<int> f2= getFrequency(nums2);
        
        vector<int> ans;
        for(int i=0; i<f1.size(); i++){
            int count= min(f1[i], f2[i]);
            while(count){
                ans.push_back(i);
                count--;
            }
        }
        
        return ans;
    }
};