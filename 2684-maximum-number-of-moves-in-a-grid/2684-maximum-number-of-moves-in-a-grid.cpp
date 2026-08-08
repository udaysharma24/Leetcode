class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            dp[i][0]=0;
            visited[i][0]=true;
        }
        for(int j=1; j<n; j++){
            for(int i=0; i<m; i++){
                if(grid[i][j]>grid[i][j-1] && visited[i][j-1]){
                    dp[i][j]=max(dp[i][j-1]+1,dp[i][j]);
                    visited[i][j]=true;
                }
                if(i>0 && grid[i][j]>grid[i-1][j-1] && visited[i-1][j-1]){
                    dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
                    visited[i][j]=true;
                }
                if(i<m-1 && grid[i][j]>grid[i+1][j-1] && visited[i+1][j-1]){
                    dp[i][j]=max(dp[i+1][j-1]+1,dp[i][j]);
                    visited[i][j]=true;
                }
                else
                    dp[i][j]=max(0,dp[i][j]);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        int mx=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j])
                    mx=max(dp[i][j],mx);
            }
        }
        return mx;
    }
};