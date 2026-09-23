class Solution {
public:
    void solve(int sindex, vector<int> options, int k, vector<bool>& visited, vector<int>& v, vector<vector<int>>& ans){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=sindex; i<options.size(); i++){
            if(!visited[i]){
                v.push_back(options[i]);
                visited[i]=true;
                solve(i+1,options,k,visited,v,ans);
                v.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> options;
        vector<int> v;
        vector<vector<int>> ans;
        vector<bool> visited(n,false);
        for(int i=1; i<=n; i++){
            options.push_back(i);
        }
        solve(0,options,k,visited,v,ans);
        return ans;
    }
};