class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        // vector<int> seq(n,-1);
        // for(int i=0; i<diff.size(); i++){ //started from idx, then to respective left & right.
        //     int index=diff[i][0];
        //     int maxval=diff[i][1];
        //     seq[index]=maxval;
        // }
        // for(int i=1; i<n; i++){
        //     int low=seq[i-1];
        //     int high=seq[i]+diff[i-1];
        //     while(low<=high){
        //         int mid=(low+high)/2;
        //         if(mid<=maxval){
        //             seq[i]=mid;
        //             low=mid+1;
        //         }
        //         else
        //             high=mid-1;
        //     }

        // }

        vector<int> mn(n,INT_MAX);
        vector<int> mx(n,INT_MAX);
        vector<int> ans(n,INT_MAX);
        mn[0]=0;
        mx[0]=0;
        ans[0]=0;
        for(int i=0; i<restrictions.size(); i++){
            int index=restrictions[i][0];
            int maxval=restrictions[i][1];
            mn[index]=maxval;
            mx[index]=maxval;
        }
        for(int i=0; i<n-1; i++){
            mn[i+1]=min(mn[i]+diff[i],mn[i+1]);
        }
        for(int i=n-2; i>=0; i--){
            mn[i]=min(mn[i+1]+diff[i],mn[i]);
        }
        return *max_element(mn.begin(),mn.end());
    }
};