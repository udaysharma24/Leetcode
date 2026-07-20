class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        int index=1;
        int target=n*n;
        while(left<=right && top<=bottom){
            for(int j=left; j<=right; j++){
                matrix[top][j]=index;
                index++;
            }
            top++;
            if(index>target)
                break;
            for(int i=top; i<=bottom; i++){
                matrix[i][right]=index;
                index++;
            }
            right--;
            if(index>target)
                break;
            for(int j=right; j>=left; j--){
                matrix[bottom][j]=index;
                index++;
            }
            bottom--;
            if(index>target)
                break;
            for(int i=bottom; i>=top; i--){
                matrix[i][left]=index;
                index++;
            }
            left++;
            if(index>target)
                break;
        }
        return matrix;
    }
};