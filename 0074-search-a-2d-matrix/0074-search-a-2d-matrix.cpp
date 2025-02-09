class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowc=0;
        int lowr=0;
        int highc=matrix[0].size()-1;
        int highr=matrix.size()-1;
        int midr=(lowr+highr)/2;
        int midc=(lowc+highc)/2;
        while(lowr<=highr)
        {
            if(matrix[midr][(matrix[0].size()-1)]<target)
            {
                lowr=midr+1;
                midr=(lowr+highr)/2;
            }
            else if(target<matrix[midr][0])
            {
                highr=midr-1;
                midr=(lowr+highr)/2;
            }
            else
                break;
        }
        while(lowc<=highc)
        {
            if(matrix[midr][midc]<target)
            {
                lowc=midc+1;
                midc=(lowc+highc)/2;
            }
            else if(matrix[midr][midc]>target)
            {
                highc=midc-1;
                midc=(lowc+highc)/2;
            }
            else if(matrix[midr][midc]==target)
                return true;
        }
        return false;
    }
};