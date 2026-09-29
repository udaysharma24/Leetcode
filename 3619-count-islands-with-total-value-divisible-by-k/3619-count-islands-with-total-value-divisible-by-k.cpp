class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        queue<pair<int,int>> qp;
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                long long int value=0;
                if(grid[i][j]>0 && !visited[i][j]){
                    qp.push({i,j});
                    visited[i][j]=true;
                }
                while(!qp.empty()){
                    int r=qp.front().first;
                    int c=qp.front().second;
                    value+=grid[r][c];
                    qp.pop();
                    if(r+1<m && grid[r+1][c]>0 && !visited[r+1][c]){
                        qp.push({r+1,c});
                        visited[r+1][c]=true;
                    }
                    if(r-1>=0 && grid[r-1][c]>0 && !visited[r-1][c]){
                        qp.push({r-1,c});
                        visited[r-1][c]=true;
                    }
                    if(c+1<n && grid[r][c+1]>0 && !visited[r][c+1]){
                        qp.push({r,c+1});
                        visited[r][c+1]=true;
                    }
                    if(c-1>=0 && grid[r][c-1]>0 && !visited[r][c-1]){
                        qp.push({r,c-1});
                        visited[r][c-1]=true;
                    }
                }
                if(value>0 && value%k==0)
                    cnt++;
            }
        }
        return cnt;
    }
};