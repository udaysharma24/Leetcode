class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        if(is_sorted(nums.begin(), nums.end()))
            return 0;
        else if(is_sorted(nums.begin(), nums.end(), greater<int>()))
            return abs(nums[n-1]-nums[0]);
        else
        {
            long long int ans=0;
            for(int i=0; i<n-1; i++)
            {
                ans+=max(0,nums[i]-nums[i+1]);
            }
            return ans;
        }
    }
};