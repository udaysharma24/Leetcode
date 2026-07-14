class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int,char>> qp;
        vector<bool> visited(n,false);
        vector<char> colour(n);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                qp.push({i,'r'});
                colour[i]='r';
                visited[i]=true;
                while(!qp.empty()){
                    int temp=qp.front().first;
                    qp.pop();
                    for(int j=0; j<graph[temp].size(); j++){
                        if(visited[graph[temp][j]] && colour[temp]==colour[graph[temp][j]])
                            return false;
                        else if(visited[graph[temp][j]] && colour[temp]!=colour[graph[temp][j]])
                            continue;
                        else{
                            if(colour[temp]=='r')
                                colour[graph[temp][j]]='b';
                            else
                                colour[graph[temp][j]]='r';
                            visited[graph[temp][j]]=true;
                            qp.push({graph[temp][j],colour[graph[temp][j]]});
                        }
                    }
                }
            }
        }
        return true;
    }
};