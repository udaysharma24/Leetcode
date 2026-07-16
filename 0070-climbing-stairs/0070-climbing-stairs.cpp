class Solution {
public:
    vector<int> dp=vector<int>(46,-1);
    int climbStairs(int n) {
        dp[1]=1;
        dp[2]=2;
        if(dp[n]!=-1)
            return dp[n];
        else{
            for(int i=3; i<=n; i++){
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
    }
};