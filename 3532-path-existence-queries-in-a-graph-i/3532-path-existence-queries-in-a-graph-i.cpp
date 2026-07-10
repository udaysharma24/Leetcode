class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> adj[n+1];
        bool flag=false;
        unordered_map<int,int> um;
        int start=0;
        int comp=0;
        for(int i=1; i<n; i++){  //divided into separate connected components
            if(nums[i]-nums[i-1]<=maxDiff){
                adj[i].push_back(i-1);
                adj[i-1].push_back(i);
                um[i]=comp;
                um[i-1]=comp;
            }
            else{
                um[i-1]=comp;
                comp++;
                um[i]=comp;
            }
        }
        vector<bool> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            int src=queries[i][0];
            int dest=queries[i][1];
            if(n==1)
                ans[i]=true;
            else if(um[src]==um[dest])
                ans[i]=true;
            else
                ans[i]=false;
        }
        return ans;
    }
};