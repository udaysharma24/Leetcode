class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<tuple<int,int,int>> qt;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2 && !visited[i][j]){
                    qt.push({i,j,0});
                    visited[i][j]=true;
                }
            }
        }
        int minutes=0;
        while(!qt.empty()){
            int r=get<0>(qt.front());
            int c=get<1>(qt.front());
            int mins=get<2>(qt.front());
            minutes=max(minutes,mins);
            qt.pop();
            if(r+1<m && grid[r+1][c]==1 && !visited[r+1][c]){
                qt.push({r+1,c,mins+1});
                visited[r+1][c]=true;
                grid[r+1][c]=2;
            }
            if(r-1>=0 && grid[r-1][c]==1 && !visited[r-1][c]){
                qt.push({r-1,c,mins+1});
                visited[r-1][c]=true;
                grid[r-1][c]=2;
            }
            if(c+1<n && grid[r][c+1]==1 && !visited[r][c+1]){
                qt.push({r,c+1,mins+1});
                visited[r][c+1]=true;
                grid[r][c+1]=2;
            }
            if(c-1>=0 && grid[r][c-1]==1 && !visited[r][c-1]){
                qt.push({r,c-1,mins+1});
                visited[r][c-1]=true;
                grid[r][c-1]=2;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return minutes;
    }
};