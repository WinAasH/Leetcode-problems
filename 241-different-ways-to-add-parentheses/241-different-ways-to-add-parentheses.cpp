class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i=0; i<expression.length(); i++){
            if(expression[i]=='*'  ||  expression[i]=='+'  ||  expression[i]=='-'){
                string a= expression.substr(0, i);
                string b= expression.substr(i+1);
                vector<int> a1= diffWaysToCompute(a);
                vector<int> b1= diffWaysToCompute(b);
                for(int x: a1){
                    for(int y: b1){
                        if(expression[i]=='+'){
                            ans.push_back(x+y);
                        }
                        else if(expression[i]=='-'){
                            ans.push_back(x-y);
                        }
                        else{
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(ans.size()==0){
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};