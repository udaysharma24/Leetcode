class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n=maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        long long int ans=0LL;
        int temp=INT_MAX;
        for(int i=0; i<n; i++){
            int height=min(temp,maximumHeight[i]);
            if(height==0)
                return -1;
            ans+=(long long)height;
            temp=height-1;
        }
        return ans;
    }
};