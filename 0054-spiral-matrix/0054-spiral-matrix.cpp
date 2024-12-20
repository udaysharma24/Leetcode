class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> a;
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        while(top<=bottom && left<=right)
        {
            for(int j=left; j<=right; j++)
            {
                a.push_back(matrix[top][j]);
            }
            top++;
            for(int i=top; i<=bottom; i++)
            {
                a.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            {
                for(int j=right; j>=left; j--)
                {
                    a.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom; i>=top; i--)
                {
                    a.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return a;
    }
};