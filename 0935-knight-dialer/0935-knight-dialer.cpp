class Solution {
public:
    const int MOD=1e9+7;
    vector<int> dp={2,2,2,2,3,0,3,2,2,2};
    vector<vector<int>> state=vector<vector<int>> (10, vector<int>(5001, -1));
    vector<int> adj[10]={{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
    int addops(int node, int n, long long int ans){
        if(n==2)
            return dp[node];
        for(int i=0; i<adj[node].size(); i++){
            if(state[adj[node][i]][n-1]!=-1)
                ans=(ans+state[adj[node][i]][n-1])%MOD;
            else{
                state[adj[node][i]][n-1]=addops(adj[node][i],n-1,0);
                ans=(ans+state[adj[node][i]][n-1])%MOD;
            }
        }
        return ans;
    }
    int knightDialer(int n) {
        int MOD=1e9+7;
        if(n==1)
            return 10;
        long long int totalops=0LL;
        long long int ans=0LL;
        for(int i=0; i<=9; i++){
            if(state[i][n]!=-1)
                ans=state[i][n];
            else{
                state[i][n]=(addops(i,n,ans))%MOD;
                ans=state[i][n];
            }
            totalops+=ans;
            ans=0LL;
        }
        return int(totalops%MOD);
    }
};