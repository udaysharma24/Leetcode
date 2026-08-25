class Solution {
public:
    long long backtrack(
        int curindex,
        vector<bool>& visited,
        vector<int>& strength,
        int k,
        map<pair<vector<bool>, int>, long long>& dp
    ) {
        int n = strength.size();

        // All locks are broken
        bool all = true;
        for(bool x : visited) {
            if(!x) {
                all = false;
                break;
            }
        }

        if(all)
            return 0;

        // Same set of broken locks + same current lock
        // => exactly the same remaining problem
        auto state = make_pair(visited, curindex);

        if(dp.find(state) != dp.end())
            return dp[state];

        // Number of locks already broken
        int broken = 0;
        for(bool x : visited)
            broken += x;

        // Current factor
        int x = 1 + broken * k;

        // Time needed to break current lock
        long long time =
            (strength[curindex] + x - 1LL) / x;

        visited[curindex] = true;
        all = true;
        for(bool v : visited) {
            if(!v) {
                all = false;
                break;
            }
        }

        if(all) {
            visited[curindex] = false;
            return time;
        }
        long long ans = LLONG_MAX;

        // Choose ANY unvisited lock next
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                ans = min(
                    ans,
                    time + backtrack(
                        i,
                        visited,
                        strength,
                        k,
                        dp
                    )
                );
            }
        }

        visited[curindex] = false;

        return dp[state] = ans;
    }

    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();

        vector<bool> visited(n, false);

        map<pair<vector<bool>, int>, long long> dp;

        long long ans = LLONG_MAX;

        // Try every possible first lock
        for(int i = 0; i < n; i++) {
            ans = min(
                ans,
                backtrack(
                    i,
                    visited,
                    strength,
                    k,
                    dp
                )
            );
        }

        return (int)ans;
    }
};