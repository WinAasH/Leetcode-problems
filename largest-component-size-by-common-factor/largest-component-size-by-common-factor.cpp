class UnionFind{
public:
    vector<int> parent;

    UnionFind(int n){
        parent= vector<int> (n);
        for(int i=0; i<n; i++) parent[i]= i;
    }
    
    int getAbsoluteParent(int i){
        if(parent[i]==i) return i;
        
        parent[i]= getAbsoluteParent(parent[i]);
        return parent[i];
    }
    
    void unify(int i, int j){
        int absoluteParentI= getAbsoluteParent(i);
        int absoluteParentJ= getAbsoluteParent(j);
        if(absoluteParentI!=absoluteParentJ){
            parent[absoluteParentJ]= absoluteParentI;
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int mx= 0;
        for(int i: nums) mx= max(mx, i);
        
        UnionFind *uf= new UnionFind(mx+1);
        
        for(int i: nums){
            for(int j=2; j*j<=i; j++){
                if(i%j==0){
                    uf->unify(j, i);
                    uf->unify(i/j, i);
                }
            }
        }
        
        map<int, int> mp;
        int maxComponent= 0;
        for(int i: nums){
            int parent= uf->getAbsoluteParent(i);
            mp[parent]++;
            maxComponent= max(maxComponent, mp[parent]);
        }
        
        return maxComponent;
    }
};