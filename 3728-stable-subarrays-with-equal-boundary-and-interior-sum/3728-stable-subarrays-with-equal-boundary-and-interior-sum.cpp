class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {

        int n = capacity.size();

        // prefix[i] = sum of first i elements
        //
        // prefix[0] = 0
        // prefix[1] = capacity[0]
        // prefix[2] = capacity[0] + capacity[1]
        // ...
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + capacity[i - 1];
        }
        /*mp stores:mp[{prefix[l+1], capacity[l]}], where l is a possible LEFT boundary.
            Why prefix[l+1]?
            prefix[l+1] = sum(capacity[0 ... l])
            This will help us match the required interior sum.
        */
        map<pair<long long, long long>, long long> mp;
        long long ans = 0;
        /*
            Here r represents prefix indexing.
            The actual RIGHT boundary element is:
            capacity[r - 1]
            We start from r = 3 because a stable subarray
            needs at least 3 elements.
        */
        for (int r = 3; r <= n; r++) {
            /*
                Suppose capacity[r-1] is the RIGHT boundary.

                Let:

                x = capacity[r-1]

                For a stable subarray, we need:

                sum(interior) = x


                prefix[r] = sum(all elements before and including
                                   capacity[r-1])

                So:

                prefix[r] - 2*x

                represents the prefix value we need to match
                with a valid LEFT boundary.
            */
            long long tar = prefix[r] - 2LL * capacity[r - 1];


            /*
                We now add a possible LEFT boundary.

                capacity[r-3] is chosen as the left boundary
                candidate.

                We store:

                {
                    prefix[r-2],
                    capacity[r-3]
                }

                This represents information about a possible
                left endpoint.

                r-3 ensures there is enough room for the
                subarray to have length >= 3.
            */
            mp[{prefix[r - 2], capacity[r - 3]}]++;


            /*
                We look for previous LEFT boundaries satisfying:

                prefix[left+1] == tar

                AND

                capacity[left] == capacity[r-1]

                So the pair:

                {tar, capacity[r-1]}

                uniquely represents a valid stable subarray.
            */
            ans += mp[{tar, capacity[r - 1]}];
        }

        return ans;
    }
};