class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int provinces=0;
        for(int i=0; i<n; i++){
            if(visited[i])
                continue;
            visited[i]=true;
            provinces++;
            queue<int> q;
            for(int j=0; j<adj[i].size(); j++){
                if(!visited[adj[i][j]]){
                    q.push(adj[i][j]);
                    visited[adj[i][j]]=true;
                }
            }
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                for(int j=0; j<adj[temp].size(); j++){
                    if(!visited[adj[temp][j]]){
                        q.push(adj[temp][j]);
                        visited[adj[temp][j]]=true;
                    }
                }
            }
        }
        return provinces;
    }
};