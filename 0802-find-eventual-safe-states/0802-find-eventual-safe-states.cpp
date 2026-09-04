class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> outdegree(n,0);
        vector<int> ans;
        queue<int> q;
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0; i<n; i++){
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            ans.push_back(temp);
            q.pop();
            for(int i=0; i<adj[temp].size(); i++){
                outdegree[adj[temp][i]]--;
                if(outdegree[adj[temp][i]]==0)
                    q.push(adj[temp][i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};