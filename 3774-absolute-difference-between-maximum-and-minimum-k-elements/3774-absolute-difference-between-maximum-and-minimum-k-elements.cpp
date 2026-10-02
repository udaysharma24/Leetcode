class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lsum=0;
        int rsum=0;
        for(int i=0; i<k; i++){
            lsum+=nums[i];
            rsum+=nums[n-i-1];
        }
        return rsum-lsum;
    }
};