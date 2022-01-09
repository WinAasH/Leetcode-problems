class Solution {
public:
    bool isRobotBounded(string ins) {
        int x=0, y=0;
        int n= ins.size();
        int currDir= 1;
        for(int i=0; i<4; i++){
            for(int i=0; i<n; i++){
                if(ins[i]=='G'){
                    if(currDir==1)  x++;
                    else if(currDir==-1) x--;
                    else if(currDir==2)  y++;
                    else if(currDir==-2) y--;
                }
                if(ins[i]=='L'){
                    if(currDir==1)  currDir=2;
                    else if(currDir==-1) currDir=-2;
                    else if(currDir==2)  currDir=-1;
                    else if(currDir==-2) currDir=1;
                }
                if(ins[i]=='R'){
                    if(currDir==1)  currDir=-2;
                    else if(currDir==-1) currDir=2;
                    else if(currDir==2)  currDir=1;
                    else if(currDir==-2) currDir=-1;
                }
            }
            if(x==0  &&  y==0)  return true;
        }
        return false;
    }
};