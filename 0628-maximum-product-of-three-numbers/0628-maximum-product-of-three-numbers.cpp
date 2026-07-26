class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        int prod1=nums[0]*nums[1]*nums[2];
        sort(nums.begin(),nums.end());
        int prod2=nums[0]*nums[1]*nums[n-1];
        return max(prod1,prod2);
    }
};