class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=0;
        for(int i=0; i<trips.size(); i++){
            n=max(n,trips[i][2]);
        }
        vector<int> diff(n+1,0);
        for(int i=0; i<trips.size(); i++){
            diff[trips[i][1]]+=trips[i][0];
            if(trips[i][2]<=n)
                diff[trips[i][2]]-=trips[i][0];
        }
        for(int i=1; i<=n; i++){
            diff[i]+=diff[i-1];
        }
        int mx=*max_element(diff.begin(),diff.end());
        if(mx>capacity)
            return false;
        else
            return true;
    }
};