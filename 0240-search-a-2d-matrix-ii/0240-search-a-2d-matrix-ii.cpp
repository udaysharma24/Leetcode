class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++)
        {
            int low=0;
            int high=matrix[0].size()-1;
            int mid=(low+high)/2;
            while(low<=high)
            {
                if(matrix[i][mid]<target)
                {
                    low=mid+1;
                    mid=(low+high)/2;
                }
                else if(target<matrix[i][mid])
                {
                    high=mid-1;
                    mid=(low+high)/2;
                }
                else
                    return true;
            }
        }
        return false;
    }
};