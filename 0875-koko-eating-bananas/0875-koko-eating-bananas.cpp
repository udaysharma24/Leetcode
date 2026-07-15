class Solution {
public:
    long long int hourstaken(vector<int> piles, int mid){
        long long int hours=0;
        for(int i=0; i<piles.size(); i++){
            hours+=ceil((double)piles[i]/mid);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=1;
        int high=piles[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(hourstaken(piles,mid)<=(long long)h)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};