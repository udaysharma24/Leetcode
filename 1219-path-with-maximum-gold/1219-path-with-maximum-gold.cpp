class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]<=0)
            return 0;
        grid[i][j]=-grid[i][j];
        int res=max({dfs(grid,i+1,j),dfs(grid,i,j+1),dfs(grid,i-1,j),dfs(grid,i,j-1)});
        grid[i][j]=-grid[i][j];
        return grid[i][j]+res;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxgold=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                maxgold=max(maxgold, dfs(grid,i,j));
            }
        }
        return maxgold;
    }
};