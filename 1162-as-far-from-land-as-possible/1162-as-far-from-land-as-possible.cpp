class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> qp;
        vector<vector<int>> visited(n, vector<int>(n,0));
        int maxdistance=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    qp.push({i,j});
                    visited[i][j]=0;
                }
            }
        }
        while(!qp.empty()){
            int i=qp.front().first;
            int j=qp.front().second;
            qp.pop();
            if(i+1<n && visited[i+1][j]==0 && grid[i+1][j]==0){
                qp.push({i+1,j});
                visited[i+1][j]=visited[i][j]+1;
            }
            if(j+1<n && visited[i][j+1]==0 && grid[i][j+1]==0){
                qp.push({i,j+1});
                visited[i][j+1]=visited[i][j]+1;
            }
            if(i-1>=0 && visited[i-1][j]==0 && grid[i-1][j]==0){
                qp.push({i-1,j});
                visited[i-1][j]=visited[i][j]+1;
            }
            if(j-1>=0 && visited[i][j-1]==0 && grid[i][j-1]==0){
                qp.push({i,j-1});
                visited[i][j-1]=visited[i][j]+1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                maxdistance=max(maxdistance,visited[i][j]);
            }
        }
        if(maxdistance==0)
            return -1;
        return maxdistance;
    }
};