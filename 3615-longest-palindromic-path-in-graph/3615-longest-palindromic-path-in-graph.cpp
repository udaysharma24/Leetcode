class Solution {
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int totalMasks = 1 << n;

        vector<vector<vector<bool>>> dp(
            totalMasks,
            vector<vector<bool>>(
                n, vector<bool>(n, false)
            )
        );

        int ans = 1;

        // Case 1: Single-node palindromes.
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            dp[mask][i][i] = true;
        }

        // Case 2: Two adjacent nodes with equal labels.
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (label[u] == label[v]) {
                int mask = (1 << u) | (1 << v);

                dp[mask][u][v] = true;
                dp[mask][v][u] = true;

                ans = 2;
            }
        }

        // Process every mask.
        for (int mask = 1; mask < totalMasks; mask++) {

            int len = __builtin_popcount((unsigned)mask);

            for (int u = 0; u < n; u++) {

                if (!(mask & (1 << u)))
                    continue;

                for (int v = 0; v < n; v++) {

                    if (!(mask & (1 << v)))
                        continue;

                    if (!dp[mask][u][v])
                        continue;

                    // This palindrome is valid.
                    ans = max(ans, len);

                    // Extend both ends.
                    for (int x : adj[u]) {

                        if (mask & (1 << x))
                            continue;

                        for (int y : adj[v]) {

                            if (x == y)
                                continue;

                            if (mask & (1 << y))
                                continue;

                            if (label[x] != label[y])
                                continue;

                            int newMask =
                                mask | (1 << x) | (1 << y);

                            dp[newMask][x][y] = true;
                        }
                    }
                }
            }
        }

        return ans;
    }
};