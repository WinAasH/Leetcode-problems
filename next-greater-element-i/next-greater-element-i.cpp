class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        int l1= n1.size(), l2= n2.size();
        unordered_map<int, int> nextGreater;
        stack<int> st;
        for(int i=l2-1; i>=0; i--){
            while(!st.empty()  &&  st.top()<=n2[i]){
                st.pop();
            }
            if(st.empty()){
                nextGreater[n2[i]]= -1;
            }
            else{
                nextGreater[n2[i]]= st.top();
            }
            st.push(n2[i]);
        }
        
        for(int i=0; i<l1; i++){
            auto it= nextGreater.find(n1[i]);
            n1[i]= it->second;
        }
        
        return n1;
    }
};