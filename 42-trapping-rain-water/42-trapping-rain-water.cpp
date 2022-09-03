class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int,int>> st;
        st.push({height[0],0});
        int ans=0;
        for(int i=1;i<height.size();i++){
            cout<<ans<<" ";
            if(!st.empty()  &&  height[i]<=st.top().first){
                st.push({height[i],i});
            }
            else{
                while(!st.empty()&&st.top().first<height[i]){
                    pair<int,int> temp=st.top();
                    st.pop();
                    int width;
                    if(!st.empty()) width=i-st.top().second-1;
                    else width=0;
                    int heightc=0;
                    if(!st.empty()) heightc=min(height[i],st.top().first)-temp.first;
                    ans+=heightc*width;
                }
                st.push({height[i],i});
            }
        }
        return ans;
    }

};