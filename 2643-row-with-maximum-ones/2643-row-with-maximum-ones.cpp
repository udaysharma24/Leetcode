class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=0,numones=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0; i<m; i++){
            int ones=0;
            for(int j=0; j<n; j++){
                if(mat[i][j]==1)
                    ones++;
            }
            if(ones>numones){
                numones=ones;
                row=i;
            }
        }
        vector<int> ans={row,numones};
        return ans;
    }
};