class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        int qsize=queries.size();
        vector<int> oprow(qsize);
        vector<int> clorow(qsize);
        vector<int> opcol(qsize);
        vector<int> clocol(qsize);
        for(int i=0; i<qsize; i++){
            oprow[i]=queries[i][0];
            opcol[i]=queries[i][1];
            clorow[i]=queries[i][2];
            clocol[i]=queries[i][3];
        }
        for(int i=0; i<qsize; i++){
            for(int j=oprow[i]; j<=clorow[i]; j++){
                mat[j][opcol[i]]++;
                if(clocol[i]+1<n)
                    mat[j][clocol[i]+1]--;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        return mat;
    }
};