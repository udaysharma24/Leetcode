// Multi-Source BFS

class Solution {
public:
    vector<vector<int>> multisource_bfs(vector<vector<int>> &adj, map<pair<int,int>,bool>& visited, vector<vector<int>> sources){
        int n=adj.size();
        int m=adj[0].size();
        queue<tuple<int,int,int>> qt;
        for(int i=0; i<sources.size(); i++)
        {
            int r=sources[i][0];
            int c=sources[i][1];
            int val=sources[i][2];
            qt.push({r,c,val});
            visited[{r,c}]=true;
        }
        while(!qt.empty()){
            int r=get<0>(qt.front());
            int c=get<1>(qt.front());
            qt.pop();
            if(r>0 && adj[r-1][c]==0 && !visited[{r-1,c}])
            {
                qt.push({r-1,c,adj[r][c]});
                visited[{r-1,c}]=true;
                adj[r-1][c]=adj[r][c];
            }
            if(c>0 && adj[r][c-1]==0 && !visited[{r,c-1}])
            {
                qt.push({r,c-1,adj[r][c]});
                visited[{r,c-1}]=true;
                adj[r][c-1]=adj[r][c];
            }
            if(r<n-1 && adj[r+1][c]==0 && !visited[{r+1,c}])
            {
                qt.push({r+1,c,adj[r][c]});
                visited[{r+1,c}]=true;
                adj[r+1][c]=adj[r][c];
            }
            if(c<m-1 && adj[r][c+1]==0 && !visited[{r,c+1}])
            {
                qt.push({r,c+1,adj[r][c]});
                visited[{r,c+1}]=true;
                adj[r][c+1]=adj[r][c];
            }
        }
        return adj;
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        sort(sources.begin(), sources.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });
        vector<vector<int>> adj(n, vector<int>(m,0));
        for(int i=0; i<sources.size(); i++)
        {
            int r=sources[i][0];
            int c=sources[i][1];
            int val=sources[i][2];
            adj[r][c]=val;
        }
        map<pair<int,int>,bool> visited;
        return multisource_bfs(adj, visited, sources);
    }
};