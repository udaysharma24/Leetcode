class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<int> child[numCourses];
        vector<bool> visited(numCourses,false);
        for(int i=0; i<prerequisites.size(); i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            indegree[a]++;
            child[b].push_back(a);
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0; i<child[temp].size(); i++){
                indegree[child[temp][i]]--;
                if(indegree[child[temp][i]]==0 && !visited[child[temp][i]]){
                    q.push(child[temp][i]);
                    visited[child[temp][i]]=true;
                }
            }
        }
        for(int i=0; i<numCourses; i++){
            if(indegree[i]!=0)
                return false;
        }
        return true;
    }
};