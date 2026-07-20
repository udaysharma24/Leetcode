class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        k%=(m*n);
        if(k==0)
            return grid;
        int rowshift=k/n;
        int colshift=k%n;
        if(rowshift>0){
            for(int i=0; i<rowshift; i++){
                vector<int> temp=grid[m-1];
                grid.insert(grid.begin(),temp);
                grid.pop_back();
            }
        }
        if(colshift>0){
            for(int j=0; j<colshift; j++){
                int temp=grid[m-1][n-1];
                grid[0].insert(grid[0].begin(),temp);
                grid[m-1].pop_back();
                for(int i=0; i<m-1; i++){
                    int temp=grid[i][grid[i].size()-1];
                    grid[i+1].insert(grid[i+1].begin(),temp);
                    grid[i].pop_back();
                }
            }
        }
        return grid;
    }
};