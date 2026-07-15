class Solution {
public:
    #define ll long long
    long long int totaltrips(vector<int> &time, long long mid){
        long long int trips=0LL;
        for(int i=0; i<time.size(); i++){
            trips+=((ll)(mid/time[i]));
        }
        return (ll)trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low=1;
        long long int high=1e14;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(totaltrips(time,mid)>=(ll)totalTrips)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};