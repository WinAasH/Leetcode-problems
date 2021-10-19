class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        int l1= n1.size(), l2= n2.size();
        vector<int> nextGreater(l2);
        stack<int> st;
        for(int i=l2-1; i>=0; i--){
            while(!st.empty()  &&  st.top()<=n2[i]){
                st.pop();
            }
            if(st.empty()){
                nextGreater[i]= -1;
            }
            else{
                nextGreater[i]= st.top();
            }
            st.push(n2[i]);
        }
        
        for(int i=0; i<l1; i++){
            for(int j=0; j<l2; j++){
                if(n1[i]==n2[j]){
                    n1[i]= nextGreater[j];
                    break;
                }
            }
        }
        
        return n1;
    }
};