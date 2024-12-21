class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        vector<int> row={1};
        int cnt=1;
        triangle.push_back(row);
        cnt++;
        for(int i=1; i<numRows; i++)
        {
            vector<int> row(cnt,1);
            for(int j=1; j<row.size()-1; j++)
            {
                row[j]=(triangle[i-1][j-1]+triangle[i-1][j]);
            }
            triangle.push_back(row);
            cnt++;
        }
        return triangle;
    }
};