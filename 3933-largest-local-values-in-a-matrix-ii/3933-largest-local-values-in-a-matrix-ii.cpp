class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        static int psum[201][201][201] = {};

        // psum[x][i+1][j+1] =
        // number of cells > x in rectangle (0,0) -> (i,j)

        for(int x = 0; x <= 200; x++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    psum[x][i+1][j+1] =
                        psum[x][i][j+1]
                        + psum[x][i+1][j]
                        - psum[x][i][j]
                        + (matrix[i][j] > x);
                }
            }
        }

        int loc_max = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int x = matrix[i][j];

                if(x == 0)
                    continue;

                int r1 = max(0, i-x);
                int r2 = min(m-1, i+x);

                int c1 = max(0, j-x);
                int c2 = min(n-1, j+x);

                int cnt =
                    psum[x][r2+1][c2+1]
                    - psum[x][r1][c2+1]
                    - psum[x][r2+1][c1]
                    + psum[x][r1][c1];

                // Remove ignored corner cells

                if(i-x >= 0 && j-x >= 0 &&
                   matrix[i-x][j-x] > x)
                    cnt--;

                if(i-x >= 0 && j+x < n &&
                   matrix[i-x][j+x] > x)
                    cnt--;

                if(i+x < m && j-x >= 0 &&
                   matrix[i+x][j-x] > x)
                    cnt--;

                if(i+x < m && j+x < n &&
                   matrix[i+x][j+x] > x)
                    cnt--;

                if(cnt == 0)
                    loc_max++;
            }
        }

        return loc_max;
    }
};