class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans.push_back(grid[i][j]);
                for(int k=1; i+2*k<m && j+k<n && j-k>=0; k++){
                    int sum=grid[i][j];
                    for(int l=1; l<=k; l++){
                        sum+=grid[i+l][j-l];
                        sum+=grid[i+l][j+l];
                    }
                    for(int l=1; l<k; l++){
                        sum += grid[i+k+l][j-k+l];
                        sum += grid[i+k+l][j+k-l];
                    }
                    sum += grid[i+2*k][j];
                    ans.push_back(sum);
                }
            }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        vector<int> finalans;
        for(int x : ans){
            if(finalans.empty() || finalans.back() != x){
                finalans.push_back(x);
            }

            if(finalans.size() == 3)
                break;
        }
        return finalans;
    }
};