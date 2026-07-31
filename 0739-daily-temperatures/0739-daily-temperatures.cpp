class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> nge(n,0);
        if(temperatures.size()==1)
            nge[0]=0;
        else{
            stack<pair<int,int>> st;
            for(int i=n-1; i>=0; i--){
                if(st.empty()){
                    st.push({temperatures[i],i});
                    nge[i]=st.top().second-i;
                }
                else if(temperatures[i]>=st.top().first){
                    while(!st.empty() && temperatures[i]>=st.top().first){
                        st.pop();
                    }
                    if(st.empty())
                        st.push({temperatures[i],i});
                    nge[i]=st.top().second-i;
                    st.push({temperatures[i],i});
                }
                else if(temperatures[i]<st.top().first){
                    nge[i]=st.top().second-i;
                    st.push({temperatures[i],i});
                }
                // cout<<nge[i]<<" ";
            }
        }
        return nge;
    }
};