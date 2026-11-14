class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> psum(n);
        psum[0]=nums[0];
        for(int i=1; i<n; i++){
            psum[i]=psum[i-1]+nums[i];
        }
        int minsum=INT_MAX;
        for(int i=l; i<=r; i++){
            if(psum[i-1]>0)
                minsum=min(minsum,psum[i-1]);
            for(int j=0; j+i<n; j++){
                if(j+i<n && psum[j+i]-psum[j]>0)
                    minsum=min(minsum,psum[j+i]-psum[j]);
            }
        }
        if(minsum==INT_MAX)
            return -1;
        return minsum;
    }
};