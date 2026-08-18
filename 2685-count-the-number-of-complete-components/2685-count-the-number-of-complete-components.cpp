class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        int com_components=0;
        for(int i=0; i<n; i++){
            int nodes=0;
            int minadjsize=INT_MAX;
            if(q.empty() && !visited[i]){
                q.push(i);
                nodes++;
                visited[i]=true;
            }
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                minadjsize=min(minadjsize,int(adj[temp].size()));
                for(int j=0; j<adj[temp].size(); j++){
                    if(!visited[adj[temp][j]]){
                        q.push(adj[temp][j]);
                        nodes++;
                        visited[adj[temp][j]]=true;
                    }
                }
            }
            if(nodes>2 && nodes-1==minadjsize)
                com_components++;
            else if(nodes<=2 && nodes>0)
                com_components++;
        }
        return com_components;
    }
};