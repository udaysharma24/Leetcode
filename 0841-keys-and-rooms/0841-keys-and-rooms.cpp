class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0; i<rooms[temp].size(); i++){
                if(!visited[rooms[temp][i]]){
                    q.push(rooms[temp][i]);
                    visited[rooms[temp][i]]=true;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};