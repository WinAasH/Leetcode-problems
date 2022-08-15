class Solution {
public:
    int romanToInt(string s) {
        int ans= 0, n= s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='I'){
                if(i+1<n  &&  (s[i+1]=='V'  ||  s[i+1]=='X')){
                    if(s[i+1]=='V'){
                        ans+= 4;
                    }
                    else if(s[i+1]=='X'){
                        ans+= 9;
                    }
                    i++;
                }
                else{
                    ans+= 1;
                }
            }
            else if(s[i]=='V'){
                ans+= 5;
            }
            else if(s[i]=='X'){
                if(i+1<n  &&  (s[i+1]=='L'  ||  s[i+1]=='C')){
                    if(s[i+1]=='L'){
                        ans+= 40;
                    }
                    else if(s[i+1]=='C'){
                        ans+= 90;
                    }
                    i++;
                }
                else{
                    ans+= 10;
                }
            }
            else if(s[i]=='L'){
                ans+= 50;
            }
            else if(s[i]=='C'){
                if(i+1<n  &&  (s[i+1]=='D'  ||  s[i+1]=='M')){
                    if(s[i+1]=='D'){
                        ans+= 400;
                    }
                    else if(s[i+1]=='M'){
                        ans+= 900;
                    }
                    i++;
                }
                else{
                    ans+= 100;
                }
            }
            else if(s[i]=='D'){
                ans+= 500;
            }
            else if(s[i]=='M'){
                ans+= 1000;
            }
        }
        return ans;
    }
};