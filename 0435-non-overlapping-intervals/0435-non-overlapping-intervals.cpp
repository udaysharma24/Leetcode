class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
            if (a[1] == b[1])
                return a[0]>b[0];
            return a[1]<b[1];
        });
        int erased=0;
        int prev=0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=intervals[prev][1])
                prev=i;
            else
                erased++;
        }
        return erased;
    }
};