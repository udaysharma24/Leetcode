class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        vector<bool> visited(n,false);
        vector<int> reachtime(n,INT_MAX);
        for(int i=0; i<times.size(); i++){
            int src=times[i][0]-1;
            int dest=times[i][1]-1;
            int pathtime=times[i][2];
            adj[src].push_back({dest,pathtime});
        }
        queue<pair<int,int>> qp;
        qp.push({k-1,0});
        visited[k-1]=true;
        reachtime[k-1]=0;
        while(!qp.empty()){
            int temp=qp.front().first;
            int time=qp.front().second;
            qp.pop();
            for(int i=0; i<adj[temp].size(); i++){
                int dest=adj[temp][i].first;
                int pathtime=adj[temp][i].second;
                if(pathtime+time<reachtime[dest]){
                    reachtime[dest]=pathtime+time;
                    visited[dest]=true;
                    qp.push({dest,reachtime[dest]});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(visited[i]==false)
                return -1;
        }
        return *max_element(reachtime.begin(),reachtime.end());
    }
};