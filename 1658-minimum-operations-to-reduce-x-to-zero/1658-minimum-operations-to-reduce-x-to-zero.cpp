class Solution {
public:
    // int solve(vector<int>& nums, int l, int r, int x, vector<vector<int>>& dp){
    //     if(l<nums.size() && r>=0 && dp[l][r]!=-1)
    //         return dp[l][r];
    //     else if(l<nums.size() && r>=0 && x==0)
    //         return dp[l][r]=0;
    //     else if(l<nums.size() && r>=0 && x<0)
    //         return dp[l][r]=1e9;
    //     else if(l<nums.size() && r>=0 && x>0)
    //         return dp[l][r]=min(1+solve(nums,l+1,r,x-nums[l],dp), 1+solve(nums,l,r-1,x-nums[r],dp));
    //     return 1e9;
    // }
    int minOperations(vector<int>& nums, int x) {
        // int n=nums.size();
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // int ans=solve(nums,0,n-1,x,dp);
        // if(ans>=1e9)
        //     return -1;
        // return ans;
        int l=0;
        int r=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        long long int sum=0;
        int maxcnt=-1;
        if(total-x<0)
            return -1;
        while(l<=r && r<nums.size()){
            if(sum<total-x){
                sum+=nums[r];
                r++;
            }
            else if(sum==total-x){
                maxcnt=max(maxcnt,r-l);
                sum+=nums[r];
                r++;
            }
            else{
                while(sum>total-x){
                    sum-=nums[l];
                    l++;
                }
            }
        }
        while(sum>total-x){
            sum-=nums[l];
            l++;
        }
        if(sum==total-x)
            maxcnt=max(maxcnt,r-l);
        if(maxcnt==-1)
            return -1;
        return nums.size()-maxcnt;
    }
};