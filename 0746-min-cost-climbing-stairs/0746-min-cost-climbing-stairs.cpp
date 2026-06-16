class Solution {
public:
    int f(vector<int> cost, int index, vector<int>& dp){
        if(index<0)
            return 0;
        if(index==0 || index==1)
            return dp[index]=cost[index];
        if(dp[index]!=-1)
            return dp[index];
        else{
            dp[index]=cost[index] + min(f(cost,index-1,dp), f(cost,index-2,dp));
            dp[index-1]=cost[index-1] + min(f(cost,index-2,dp), f(cost,index-3,dp));
            return min(dp[index],dp[index-1]);
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        if(n==2)
            return dp[1]=min(cost[0],cost[1]);
        if(dp[n-1]!=-1)
            return dp[n-1];
        else
        {
            dp[n-1]=cost[n-1] + min(f(cost,n-2,dp), f(cost,n-3,dp));
            dp[n-2]=cost[n-2] + min(f(cost,n-3,dp), f(cost,n-4,dp));
            // if(n==6)
            //     cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<" "<<dp[5]<<"\n";
            return min(dp[n-1],dp[n-2]);
        }
    }
};