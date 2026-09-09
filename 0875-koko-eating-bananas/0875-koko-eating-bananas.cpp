class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int low=1;
        int high=piles[n-1];
        int finalans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            long long int ans=0;
            for(int i=0; i<n; i++){
                if(piles[i]%mid==0)
                    ans+=(piles[i]/mid);
                else
                    ans+=(piles[i]/mid)+1;
            }
            cout<<ans<<"\t"<<mid<<"\n";
            if(ans<=h){
                finalans=min(mid,finalans);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return finalans;
    }
};