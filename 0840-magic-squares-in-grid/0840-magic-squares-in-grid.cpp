class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                unordered_set<int> us;
                if(grid[i-1][j-1]<10 && grid[i-1][j-1]>0)
                    us.insert(grid[i-1][j-1]);
                if(grid[i-1][j]<10 && grid[i-1][j]>0)
                    us.insert(grid[i-1][j]);
                if(grid[i-1][j+1]<10 && grid[i-1][j+1]>0)
                    us.insert(grid[i-1][j+1]);
                if(grid[i][j-1]<10 && grid[i][j-1]>0)
                    us.insert(grid[i][j-1]);
                if(grid[i][j]<10 && grid[i][j]>0)
                    us.insert(grid[i][j]);
                if(grid[i][j+1]<10 && grid[i][j+1]>0)
                    us.insert(grid[i][j+1]);
                if(grid[i+1][j-1]<10 && grid[i+1][j-1]>0)
                    us.insert(grid[i+1][j-1]);
                if(grid[i+1][j]<10 && grid[i+1][j]>0)
                    us.insert(grid[i+1][j]);
                if(grid[i+1][j+1]<10 && grid[i+1][j+1]>0)
                    us.insert(grid[i+1][j+1]);
                int rsum1=grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1];
                int rsum2=grid[i][j-1]+grid[i][j]+grid[i][j+1];
                int rsum3=grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                int csum1=grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1];
                int csum2=grid[i-1][j]+grid[i][j]+grid[i+1][j];
                int csum3=grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1];
                int dsum1=grid[i-1][j-1]+grid[i+1][j+1];
                int dsum2=grid[i-1][j+1]+grid[i+1][j-1];
                if(us.size()==9 && rsum1==rsum2 && rsum2==rsum3 && csum1==csum2 && csum2==csum3 && dsum1==dsum2)
                    ans++;
            }
        }
        return ans;
    }
};