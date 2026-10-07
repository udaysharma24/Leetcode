class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long int maxarea=0;   
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int left=max(bottomLeft[i][0],bottomLeft[j][0]);
                int right=min(topRight[i][0],topRight[j][0]);
                int down=max(bottomLeft[i][1],bottomLeft[j][1]);
                int top=min(topRight[i][1],topRight[j][1]);
                int length=right-left;
                int breadth=top-down;
                int side=min(length,breadth);
                if(length>0 && breadth>0)
                    maxarea=max(maxarea,(long long)side*side);
            }
        }
        return maxarea;
    }
};