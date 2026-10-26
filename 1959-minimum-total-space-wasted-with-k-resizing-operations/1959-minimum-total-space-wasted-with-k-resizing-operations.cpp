
class Solution {
public:
    int dp[205][205];
    int INF = 1e9;

    int solve(vector<int>& nums, int idx, int k) {
        int n = nums.size();

        if (idx == n) return 0;
        if (k < 0) return INF;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int sum = 0, mx = 0;
        int ans = INF;

        // Try every possible ending index of this group
        for (int i = idx; i < n; i++) {
            sum += nums[i];
            mx = max(mx, nums[i]);

            // Waste = total capacity - actual usage
            int waste = mx * (i - idx + 1) - sum;

            // Current group + remaining array
            ans = min(ans, waste + solve(nums, i + 1, k - 1));
        }

        return dp[idx][k] = ans;
    }

    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, k);
    }
};
