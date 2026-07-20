class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        int colstart=0;
        int rowstart=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        while(rowstart<m && colstart<n){
            for(int j=colstart; j<=n-colstart-1; j++){
                ans.push_back(matrix[rowstart][j]);
                visited[rowstart][j]=true;
            }
            if(rowstart+1>=m || n-colstart-1<0 || (rowstart+1<m && n-colstart-1>=0 && visited[rowstart+1][n-colstart-1]))
                break;
            for(int i=rowstart+1; i<=m-rowstart-1; i++){
                ans.push_back(matrix[i][n-colstart-1]);
                visited[i][n-colstart-1]=true;
            }
            if(m-rowstart-1<0 || n-2-colstart<0 || (m-rowstart-1>=0 && n-2-colstart>=0 && visited[m-rowstart-1][n-2-colstart]))
                break;
            for(int j=n-2-colstart; j>=colstart; j--){
                ans.push_back(matrix[m-rowstart-1][j]);
                visited[m-rowstart-1][j]=true;
            }
            if(m-2-rowstart<0 || visited[m-2-rowstart][colstart])
                break;
            for(int i=m-2-rowstart; i>=rowstart+1; i--){
                ans.push_back(matrix[i][colstart]);
                visited[i][colstart]=true;
            }
            rowstart++;
            colstart++;
            if(rowstart>=m || colstart>=n || (rowstart<m && colstart<n && visited[rowstart][colstart]))
                break;
        }
        return ans;
    }
};