class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long long int sum=accumulate(beans.begin(),beans.end(),0LL);
        long long int minans=LONG_MAX;
        long long int ans=0LL;
        for(int i=0; i<n; i++){
            ans=sum-((long long)(n-i)*(long long)(beans[i]));
            minans=min(ans,minans);
        }
        return minans;
    }
};