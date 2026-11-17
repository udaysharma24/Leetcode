class Solution {
public:
    int countoverlaps(int rowoffset, int coloffset, vector<vector<int>>& img1, vector<vector<int>>& img2){
        int cnt=0;
        int n=img1.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i+rowoffset>=0 && i+rowoffset<n && j+coloffset>=0 && j+coloffset<n && img1[i][j]==1 && img2[i+rowoffset][j+coloffset]==1)
                    cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<int> rowoffset(2*n-1);
        vector<int> coloffset(2*n-1);
        rowoffset[0]=-(n-1);
        coloffset[0]=-(n-1);
        for(int i=1; i<2*n-1; i++){
            rowoffset[i]=rowoffset[i-1]+1;
        }
        for(int i=1; i<2*n-1; i++){
            coloffset[i]=coloffset[i-1]+1;
        }
        int maxoverlaps=0;
        for(int i=rowoffset[0]; i<=rowoffset[2*n-2]; i++){
            for(int j=coloffset[0]; j<=coloffset[2*n-2]; j++){
                maxoverlaps=max(maxoverlaps,countoverlaps(i,j,img1,img2));
            }
        }
        return maxoverlaps;
    }
};