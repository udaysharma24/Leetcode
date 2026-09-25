class Solution {
public:
    int solve(int previndex, int curindex, vector<int>& nums, vector<vector<int>>& dp){
        if(curindex>=nums.size())
            return dp[previndex+1][curindex]=0;
        if(dp[previndex+1][curindex]!=-1)
            return dp[previndex+1][curindex];
        int ans1=0,ans2=0;
        if(previndex==-1 || nums[curindex]>nums[previndex])
            ans1=1+solve(curindex,curindex+1,nums,dp);
        ans2=solve(previndex,curindex+1,nums,dp);
        return dp[previndex+1][curindex]=max(ans1,ans2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans=solve(-1,0,nums,dp);
        return ans;
    }
};