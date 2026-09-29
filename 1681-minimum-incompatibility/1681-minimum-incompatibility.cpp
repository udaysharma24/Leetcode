class Solution {
public:
    int n, sz;
    vector<int> nums;
    vector<int> dp;

    int solve(int mask) {
        if (mask == (1 << n) - 1)
            return 0;

        if (dp[mask] != -1)
            return dp[mask];

        int first = 0;

        // First unused index
        while (mask & (1 << first))
            first++;

        int ans = INT_MAX;

        // Current group must contain 'first'
        function<void(int, int, int, int, int)> generate =
        [&](int start, int cnt, int groupMask, int mn, int mx) {

            if (cnt == sz) {
                int next = solve(mask | groupMask);

                if (next != INT_MAX)
                    ans = min(ans, mx - mn + next);

                return;
            }

            for (int i = start; i < n; i++) {

                if (mask & (1 << i))
                    continue;

                // Avoid duplicate VALUES inside this group.
                bool duplicate = false;

                for (int j = first; j < i; j++) {
                    if ((groupMask & (1 << j)) &&
                        nums[j] == nums[i]) {
                        duplicate = true;
                        break;
                    }
                }

                if (duplicate)
                    continue;

                generate(
                    i + 1,
                    cnt + 1,
                    groupMask | (1 << i),
                    min(mn, nums[i]),
                    max(mx, nums[i])
                );
            }
        };

        // Put first unused element into the group immediately.
        generate(
            first + 1,
            1,
            1 << first,
            nums[first],
            nums[first]
        );

        return dp[mask] = ans;
    }

    int minimumIncompatibility(vector<int>& arr, int k) {
        nums = arr;
        n = nums.size();
        sz = n / k;

        sort(nums.begin(), nums.end());

        // If a value appears more than k times,
        // impossible to put them into k groups.
        for (int i = 0; i < n; ) {
            int j = i;

            while (j < n && nums[j] == nums[i])
                j++;

            if (j - i > k)
                return -1;

            i = j;
        }

        dp.assign(1 << n, -1);

        return solve(0) == INT_MAX ? -1 : solve(0);
    }
};