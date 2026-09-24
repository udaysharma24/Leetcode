class Solution {
public:
    int minDistance(string word1, string word2) {
        int r=word1.length();
        int c=word2.length();
        vector<vector<int>> dp(r+1, vector<int>(c+1,0));
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return r+c-2*(dp[r][c]);
    }
};