class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0;
        int high=citations.size();
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            auto it=lower_bound(citations.begin(),citations.end(),mid);
            int val=citations.end()-it;
            if(val>=mid){
                ans=max(ans,mid);
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};