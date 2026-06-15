class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(34);
    vector<int> getRow(int rowIndex) {
        if(!dp[rowIndex].empty())
            return dp[rowIndex];
        dp[rowIndex].push_back(1);
        if(rowIndex==0) 
            return dp[rowIndex];
        dp[rowIndex-1]=getRow(rowIndex-1);
        if(rowIndex>=2)
        {
            for(int j=1; j<dp[rowIndex-1].size(); j++)
            {
                dp[rowIndex].push_back(dp[rowIndex-1][j-1]+dp[rowIndex-1][j]);
            }
        }
        dp[rowIndex].push_back(1);
        return dp[rowIndex];
    }
};