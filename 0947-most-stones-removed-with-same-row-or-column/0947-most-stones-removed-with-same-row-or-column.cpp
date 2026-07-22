class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int m=stones.size();
        int n=stones[0].size();
        // cout<<"Hi1";
        struct pairHash2 {
            size_t operator()(const pair<int,int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };
        unordered_map<pair<int,int>, vector<pair<int,int>>, pairHash2> adj;
        for (int i = 0; i < stones.size(); i++) {
            pair<int,int> u = {stones[i][0], stones[i][1]};

            for (int j = i + 1; j < stones.size(); j++) {
                pair<int,int> v = {stones[j][0], stones[j][1]};

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        // cout<<"Hi2";
        queue<pair<int,int>> qp;
        int totalstones=0;
        struct pairHash3 {
            size_t operator()(const pair<int,int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };
        unordered_map<pair<int,int>, bool, pairHash3> visited;
        for(auto &[node, neighbours] : adj){
            int stones=0;
            if(visited[node])
                continue;
            else{
                qp.push(node);
                stones++;
                visited[node]=true;
                while(!qp.empty()){
                    pair<int,int> p=qp.front();
                    qp.pop();
                    for(int j=0; j<adj[p].size(); j++){
                        if(!visited[adj[p][j]]){
                            qp.push(adj[p][j]);
                            visited[adj[p][j]]=true;
                            stones++;
                        }
                    }
                }
                cout<<stones<<" ";
                totalstones+=(stones-1);
            }
        }
        return totalstones;
    }
};