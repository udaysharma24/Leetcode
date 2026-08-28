class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int maxx=INT_MAX;
        int n=points.size();
        sort(points.begin(),points.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });
        int rect=1;
        int l=0,r=0;
        while(r<points.size() && l<points.size()){
            if(points[r][0]-points[l][0]>w){
                l=r;
                rect++;
            }
            r++;
        }
        return rect;
    }
};