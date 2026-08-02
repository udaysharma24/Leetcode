class Solution {
public:
    vector<int> bfs(int node, vector<int> adj[], int n){
        queue<int> q;
        vector<int> visited(n,false);
        vector<int> dist(n,0);
        q.push(node);
        visited[node]=true;
        dist[node]=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int j=0; j<adj[temp].size(); j++){
                if(!visited[adj[temp][j]]){
                    q.push(adj[temp][j]);
                    visited[adj[temp][j]]=true;
                    dist[adj[temp][j]]=dist[temp]+1;
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dx=bfs(x,adj,n);
        vector<int> dy=bfs(y,adj,n);
        vector<int> dz=bfs(z,adj,n);
        int special_cnt=0;
        for(int i=0; i<n; i++){
            if(pow(dx[i],2)+pow(dy[i],2)==pow(dz[i],2))
                special_cnt++;
            else if(pow(dx[i],2)+pow(dz[i],2)==pow(dy[i],2))
                special_cnt++;
            else if(pow(dz[i],2)+pow(dy[i],2)==pow(dx[i],2))
                special_cnt++;
        }
        return special_cnt;
    }
};