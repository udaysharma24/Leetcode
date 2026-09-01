class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].length();
        vector<vector<char>> classrom(m, vector<char>(n,'.'));
        int cnt = 0;
        vector<vector<int>> bit(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(classroom[i][j] == 'L')
                    bit[i][j] = cnt++;
            }
        }

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        int allmask = (1 << cnt) - 1;

        queue<tuple<int,int,int,int,int>> qt; //row,col,energy,mask,moves
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                classrom[i][j]=classroom[i][j];
                if(classroom[i][j]=='S'){
                    qt.push({i,j,energy,0,0});
                    visited[i][j][energy][0]=true;
                }
            }
        }
        while(!qt.empty()){
            int r=get<0>(qt.front());
            int c=get<1>(qt.front());
            int ener=get<2>(qt.front());
            int mask=get<3>(qt.front());
            int moves=get<4>(qt.front());
            qt.pop();
            if(mask==allmask)
                return moves;
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                // Every move costs 1 energy
                int newEnergy = ener - 1;

                if (newEnergy < 0)
                    continue;

                int newMask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    newMask |= (1 << bit[nr][nc]);
                }

                // Reset area
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    qt.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        moves + 1
                    });
                }
            }
        }
        return -1;
    }
};