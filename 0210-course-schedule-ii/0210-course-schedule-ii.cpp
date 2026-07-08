class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i=0; i<prerequisites.size(); i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        vector<int> v;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            v.push_back(temp);
            q.pop();
            for(int i=0; i<adj[temp].size(); i++){
                indegree[adj[temp][i]]--;
                if(indegree[adj[temp][i]]==0)
                    q.push(adj[temp][i]);
            }
        }
        if(v.size()!=numCourses)
            v.clear();
        return v;
    }
};