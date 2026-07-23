class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        int common_ascii=0;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+int(s1[i-1]);
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int max_common_ascii=dp[m][n];
        int total_ascii=0;
        for(int i=0; i<m; i++){
            total_ascii+=int(s1[i]);
        }
        for(int i=0; i<n; i++){
            total_ascii+=int(s2[i]);
        }
        int ans=total_ascii-(2*max_common_ascii);
        return ans;
    }
};