class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> vs(m,"");
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0)
                    vs[i].push_back('.');
                else if(j==n-1)
                    vs[i].push_back('.');
                else
                    vs[i].push_back('#');
            }
        }
        return vs;
    }
};