class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = 1e9;
        int ans = INF;

        // best[i] = shortest target-sum subarray
        // completely inside [0...i]
        vector<int> best(n, INF);

        int l = 0, sum = 0;
        int mn = INF;

        for(int r = 0; r < n; r++) {
            sum += arr[r];

            while(sum > target) {
                sum -= arr[l];
                l++;
            }

            if(sum == target) {
                int len = r - l + 1;

                // If we already have a subarray before l,
                // combine it with current one
                if(l > 0 && best[l-1] != INF)
                    ans = min(ans, best[l-1] + len);

                mn = min(mn, len);
            }

            best[r] = mn;
        }

        return ans == INF ? -1 : ans;
    }
};