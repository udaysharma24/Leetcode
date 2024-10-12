class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int currentsum=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            currentsum+=nums[i];
            maxsum=max(currentsum,maxsum);
            if(currentsum<0)
                currentsum=0;
        }
        return maxsum;
    }
};