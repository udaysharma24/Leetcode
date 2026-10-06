class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> efforts(n);
        long long int p_old=0LL;
        for(int i=0; i<n; i++){
            if(i%2==0){
                p_old+=nums[i];
                efforts[i]=-2*nums[i];
            }
            else{
                p_old-=nums[i];
                efforts[i]=2*nums[i];
            }
        }
        long long INF = 1e18;

        long long odd = efforts[0];
        long long even = -INF;

        long long maxsum = 0;

        for(int i = 1; i < n; i++) {
            long long x = efforts[i];

            long long newEven = odd + x;
            long long newOdd = max(x, even + x);

            even = newEven;
            odd = newOdd;

            maxsum = max(maxsum, even);
        }
        return p_old+maxsum;
    }
};