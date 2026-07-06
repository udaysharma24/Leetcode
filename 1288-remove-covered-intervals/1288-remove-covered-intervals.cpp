class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=intervals.size();
        int index=0;
        for(int i=1; i<intervals.size(); ){
            if(intervals[i][0]>=intervals[index][0] && intervals[i][1]<=intervals[index][1])
                intervals.erase(intervals.begin()+i);
            else{
                index=i;
                i++;
            }
        }
        // for(int i=0; i<intervals.size(); i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<"\n";
        // }
        return intervals.size();
    }
};