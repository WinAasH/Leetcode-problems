class Solution {
public:
    

    string getslope(vector<int>p1,vector<int>p2){
        //get slope of two points p1,p2.
        //cant store slope as a float since lack of accuracy. hence store it as a numerator+denominator string, each scaled by gcd so that 1/3==2/6
        int x1=p1[0];
        int y1=p1[1];
        int x2=p2[0];
        int y2=p2[1];
        if(x1==x2)return "-1";
        if(y2==y1)return "INT_MAX";
        int num=(y2-y1);
        int denom=x2-x1;
        int gcd=__gcd(num,denom);
        string m=to_string(num/gcd)+to_string(denom/gcd);
        return m;
    }
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<string,int>slope;
        int n=points.size();
        int ans=1;
        
        //for every point calculate slope of the line connecting this point to all other points ahead of it. all those points will lie in same line. 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string sp=getslope(points[i],points[j]);
                cout<<sp<<endl;
                if(slope.find(sp)!=slope.end()){
                    slope[sp]++;
                }
                else{
                    slope[sp]=2;
                }
                ans=max(ans,slope[sp]);
            }
            slope.clear();
        }
        
        return ans;
    }
};