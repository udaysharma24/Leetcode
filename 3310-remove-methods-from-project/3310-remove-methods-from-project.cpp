class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> visited(n,false);
        vector<int> adj[n];
        vector<int> ans;
        for(int i=0; i<invocations.size(); i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        queue<int> q;
        q.push(k);
        visited[k]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0; i<adj[temp].size(); i++){
                if(!visited[adj[temp][i]]){  
                    q.push(adj[temp][i]);
                    visited[adj[temp][i]]=true;
                }
            }
        }
        bool cant_delete=false;
        for(int i=0; i<invocations.size(); i++){
            if(visited[invocations[i][0]])
                continue;
            else if(visited[invocations[i][1]]){
                cant_delete=true;
                break;
            }
        }
        if(cant_delete){
            for(int i=0; i<n; i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(!visited[i])
                    ans.push_back(i);
            }
        }
        return ans;
    }
};