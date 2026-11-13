class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long int sum=accumulate(nums.begin(),nums.end(),0LL);
        int minindex=0;
        long long int mindiff=LONG_MAX;
        long long int tempsum=0LL;
        for(int i=0; i<n; i++){
            tempsum+=nums[i];
            long long int leftsum=tempsum;
            long long int leftavg=leftsum/(i+1);
            long long int rightsum=sum-leftsum;
            long long int rightavg;
            if(n-i-1==0)
                rightavg=0LL;
            if(n-i-1>0)
                rightavg=rightsum/(n-i-1);
            if(abs(rightavg-leftavg)<mindiff){
                mindiff=min(abs(rightavg-leftavg), mindiff);
                minindex=i;
            }
        }
        return minindex;
    }
};