class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(string curr: ops){
            if(curr=="C"){
                s.pop();
            }
            else if(curr=="D"){
                int i= s.top();
                int temp= i*2;
                s.push(temp);
            }
            else if(curr=="+"){
                int i1= s.top();
                s.pop();
                int i2= s.top();
                s.push(i1);
                int temp= i1+ i2;
                s.push(temp);
            }
            else{
                int i= stoi(curr);
                s.push(i);
            }
        }
        int ans= 0;
        while(!s.empty()){
            int temp= s.top();
            s.pop();
            ans+= temp;
        }
        return ans;
    }
};