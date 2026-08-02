class Solution {
public:
    int optimal(vector<int> piles, int chance, vector<vector<vector<int>>>& dp, int left, int right){
        if(chance==1 && right-left==1)
            return max(piles[left],piles[right]);
        else if(right-left==1)
            return min(piles[left],piles[right]);
        else{
            if(dp[left][right][chance]!=-1)
                return dp[left][right][chance];
            else if(chance==1)
                return dp[left][right][chance]=max(piles[left]+optimal(piles,2,dp,left+1,right), piles[right]+optimal(piles,2,dp,left,right-1));
            else if(chance==2)
                return dp[left][right][chance]=min(optimal(piles,1,dp,left+1,right), optimal(piles,1,dp,left,right-1));
        }
        return 0;
    }
    bool stoneGame(vector<int>& piles) {
        int m=piles.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(m+1, vector<int>(3,-1)));
        int left=0;
        int right=m-1;
        int alice_stones= max(piles[left]+optimal(piles,2,dp,left+1,right), piles[right]+optimal(piles,2,dp,left,right-1));
        int total_stones= accumulate(piles.begin(), piles.end(), 0);
        if(alice_stones<(total_stones+1)/2)
            return false;
        else
            return true;
    }
};