class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> qp;
        for(int j=0; j<n; j++){
            if(grid[0][j]==1 && !visited[0][j]){
                qp.push({0,j});
                visited[0][j]=true;
            }
        } 
        for(int j=0; j<n; j++){
            if(grid[m-1][j]==1 && !visited[m-1][j]){
                qp.push({m-1,j});
                visited[m-1][j]=true;
            }
        } 
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && !visited[i][0]){
                qp.push({i,0});
                visited[i][0]=true;
            }
        } 
        for(int i=0; i<m; i++){
            if(grid[i][n-1]==1 && !visited[i][n-1]){
                qp.push({i,n-1});
                visited[i][n-1]=true;
            }
        } 
        cout<<"Hi";
        while(!qp.empty()){
            int px=qp.front().first;
            int py=qp.front().second;
            qp.pop();
            if(px+1<m && grid[px+1][py]==1 && !visited[px+1][py]){
                qp.push({px+1,py});
                visited[px+1][py]=true;
            }
            if(py+1<n && grid[px][py+1]==1 && !visited[px][py+1]){
                qp.push({px,py+1});
                visited[px][py+1]=true;
            }
            if(px-1>=0 && grid[px-1][py]==1 && !visited[px-1][py]){
                qp.push({px-1,py});
                visited[px-1][py]=true;
            }
            if(py-1>=0 && grid[px][py-1]==1 && !visited[px][py-1]){
                qp.push({px,py-1});
                visited[px][py-1]=true;
            }
        }
        int enclaves=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j])
                    enclaves++;
            }
        }
        return enclaves;
    }
};