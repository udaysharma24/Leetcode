class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mn=INT_MAX;
        int profit=0;
        int totalprofit=0;
        for(int i=0; i<n; ){
            mn=min(mn,prices[i]);
            if(i+1<n && prices[i]<prices[i+1]){
                while(i+1<n && prices[i]<prices[i+1]){
                    i++;
                }
                profit=prices[i]-mn;
                totalprofit+=profit;
                profit=0;
                mn=INT_MAX;
            }
            i++;
        }
        return totalprofit;
    }
};