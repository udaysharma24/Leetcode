class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]<k)
                ans++;
        }
        return ans;
    }
};