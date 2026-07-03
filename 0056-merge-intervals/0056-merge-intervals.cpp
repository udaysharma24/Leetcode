class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(end>=intervals[i][0]){
                end=max(intervals[i][1], end);
            }
            else{
                vector<int> new1;
                new1.push_back(start);
                new1.push_back(end);
                ans.push_back(new1);
                new1.clear();
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        vector<int> new1;
        new1.push_back(start);
        new1.push_back(end);
        ans.push_back(new1);
        new1.clear();
        return ans;
    }
};