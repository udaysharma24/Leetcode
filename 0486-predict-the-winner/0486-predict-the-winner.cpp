class Solution {
public:
    int optimal(vector<int> arr, int left, int right, int chance, vector<vector<vector<int>>> &dp){
        if(right-left==1 && chance==1)
            return max(arr[left],arr[right]);
        else if(right-left==1)
            return min(arr[left],arr[right]);
        else{
            int n=arr.size();
            if(dp[left][right][chance]!=-1)
                return dp[left][right][chance];
            else if(chance==1)
                return dp[left][right][chance]=max(arr[left]+optimal(arr,left+1,right,2,dp), arr[right]+ optimal(arr,left,right-1,2,dp));
            else
                return dp[left][right][chance]=min(optimal(arr,left+1,right,1,dp), optimal(arr,left,right-1,1,dp));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()<=2)
            return true;
        else{
            int n=nums.size();
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(3,-1)));
            int p1_score= max(nums[0]+optimal(nums,1,n-1,2,dp), nums[n-1]+ optimal(nums,0,n-2,2,dp));
            int sum=accumulate(nums.begin(),nums.end(),0);
            cout<<p1_score;
            if(p1_score>=(sum+1)/2)
                return true;
            else
                return false;
        }
    }
};