class Solution {
public:
    int solve(int previndex, int curindex, vector<int>& nums, vector<vector<int>>& dp){
        int take=0,skip=0;
        if(curindex>=nums.size())
            return 0;
        else if(dp[curindex][previndex+1]!=-1)
            return dp[curindex][previndex+1];
        else if(previndex==-1 || nums[curindex]>nums[previndex])
            take=1+solve(curindex,curindex+1,nums,dp);
        skip=solve(previndex,curindex+1,nums,dp);
        return dp[curindex][previndex+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(-1,0,nums,dp);
    }
};