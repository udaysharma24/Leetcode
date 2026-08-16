class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(0);
        unordered_map<int,int> um;
        for(int i=0; i<restricted.size(); i++){
            um[restricted[i]]++;
        }
        vector<bool> visited(n);
        visited[0]=true;
        int reachable=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0; i<adj[temp].size(); i++){
                if(um.find(adj[temp][i])==um.end() && !visited[adj[temp][i]]){
                    q.push(adj[temp][i]);
                    reachable++;
                    visited[adj[temp][i]]=true;
                }
            }
        }
        return reachable;
    }
};