class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int mn=INT_MAX;
        int n=prices.size();
        for(int i=0; i<n; i++){
            mn=min(prices[i],mn);
            ans=max(prices[i]-mn,ans);
        }
        return ans;
    }
};