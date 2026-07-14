class Solution {
    const int MOD=1e9+7;
    int dp[200][201][201];
public:
    int solve(int i, vector<int> &nums, int first, int second){
        if(i==nums.size()){
            return (first && second) && (first==second);
        }
        if(dp[i][first][second]!=-1)
            return dp[i][first][second];
        int skip=solve(i+1,nums,first,second);
        int take1=solve(i+1,nums,gcd(first,nums[i]),second);
        int take2=solve(i+1,nums,first,gcd(second,nums[i]));
        dp[i][first][second]=(0LL+skip+take1+take2)%MOD;
        return dp[i][first][second];
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,0,0);
    }
};