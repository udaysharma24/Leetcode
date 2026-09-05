class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> um;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                um[grid[i][j]]++;
            }
        }
        vector<int> ans(2);
        for(int i=1; i<=n*n; i++){
            if(um[i]==2)
                ans[0]=i;
            else if(um[i]==0)
                ans[1]=i;
        }
        return ans;
    }
};