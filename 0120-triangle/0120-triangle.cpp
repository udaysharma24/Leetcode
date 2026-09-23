class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r=triangle.size();
        int c=triangle[r-1].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1,INT_MIN));
        for(int i=1; i<=r; i++){
            for(int j=1; j<=i; j++){
                if(dp[i-1][j]>INT_MIN && dp[i-1][j-1]>INT_MIN)
                    dp[i][j]=min(dp[i-1][j-1]+triangle[i-1][j-1], dp[i-1][j]+triangle[i-1][j-1]);
                else{
                    if(dp[i-1][j-1]==INT_MIN && dp[i-1][j]==INT_MIN)
                        dp[i][j]=triangle[i-1][j-1];
                    else if(dp[i-1][j-1]==INT_MIN && dp[i-1][j]>INT_MIN)
                        dp[i][j]=dp[i-1][j]+triangle[i-1][j-1];
                    else
                        dp[i][j]=dp[i-1][j-1]+triangle[i-1][j-1];
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return *min_element(dp[r].begin()+1,dp[r].end());
    }
};