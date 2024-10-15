class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(is_sorted(prices.begin(),prices.end(),greater<int>()))
            return 0;
        else if(is_sorted(prices.begin(),prices.end()))
            return (*max_element(prices.begin(),prices.end()))-(*min_element(prices.begin(),prices.end()));
        else
        {
            int bestsell=prices[n-1],ans;
            int maxprofit=0;
            for(int i=n-1; i>=0; i--)
            {
                if(prices[i]<bestsell)
                    maxprofit=max(bestsell-prices[i],maxprofit);
                bestsell=max(bestsell,prices[i]);
            }
            return maxprofit;
        }
    }
};