class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0;
        int xor2=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            xor1^=nums[i];
            xor2^=i;
        }
        xor2^=n;
        int ans=xor1^xor2;
        return ans;
    }
};