class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int minval=INT_MAX;
        int n=nums.size();
        long long int psum=0LL;
        long long int ssum=accumulate(nums.begin(),nums.end(),0LL);
        int mindex=-1;
        for(int i=0; i<n; i++){
            psum+=nums[i];
            ssum-=nums[i];
            int diff;
            if(n-i-1==0)
                diff=psum/(i+1);
            else
                diff=abs((psum/(i+1))-(ssum/(n-i-1)));
            if(diff<minval){
                minval=diff;
                mindex=i;
            }
        }
        return mindex;
    }
};