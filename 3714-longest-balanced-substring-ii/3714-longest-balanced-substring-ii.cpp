class Solution {
public:
    int longestBalanced(string s) {

        int n = s.size();
        int maxlen = 1;

        // =====================================================
        // CASE 1: Only one distinct character
        // =====================================================
        int len = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1])
                len++;
            else
                len = 1;

            maxlen = max(maxlen, len);
        }


        // =====================================================
        // CASE 2: Exactly two distinct characters
        // =====================================================

        // ---------------- A + B ----------------
        {
            vector<int> first(2*n + 1);
            vector<int> seen(2*n + 1, 0);

            int diff = 0;
            int segment = 1;

            seen[n] = segment;
            first[n] = -1;

            for(int i = 0; i < n; i++) {

                if(s[i] == 'c') {
                    segment++;
                    diff = 0;

                    seen[n] = segment;
                    first[n] = i;

                    continue;
                }

                if(s[i] == 'a')
                    diff++;
                else
                    diff--;

                int idx = diff + n;

                if(seen[idx] != segment) {
                    seen[idx] = segment;
                    first[idx] = i;
                }
                else {
                    maxlen = max(maxlen, i - first[idx]);
                }
            }
        }


        // ---------------- B + C ----------------
        {
            vector<int> first(2*n + 1);
            vector<int> seen(2*n + 1, 0);

            int diff = 0;
            int segment = 1;

            seen[n] = segment;
            first[n] = -1;

            for(int i = 0; i < n; i++) {

                if(s[i] == 'a') {
                    segment++;
                    diff = 0;

                    seen[n] = segment;
                    first[n] = i;

                    continue;
                }

                if(s[i] == 'b')
                    diff++;
                else
                    diff--;

                int idx = diff + n;

                if(seen[idx] != segment) {
                    seen[idx] = segment;
                    first[idx] = i;
                }
                else {
                    maxlen = max(maxlen, i - first[idx]);
                }
            }
        }


        // ---------------- A + C ----------------
        {
            vector<int> first(2*n + 1);
            vector<int> seen(2*n + 1, 0);

            int diff = 0;
            int segment = 1;

            seen[n] = segment;
            first[n] = -1;

            for(int i = 0; i < n; i++) {

                if(s[i] == 'b') {
                    segment++;
                    diff = 0;

                    seen[n] = segment;
                    first[n] = i;

                    continue;
                }

                if(s[i] == 'a')
                    diff++;
                else
                    diff--;

                int idx = diff + n;

                if(seen[idx] != segment) {
                    seen[idx] = segment;
                    first[idx] = i;
                }
                else {
                    maxlen = max(maxlen, i - first[idx]);
                }
            }
        }


        // =====================================================
        // CASE 3: All three distinct characters
        // =====================================================

        // State = (A-B, B-C)

        auto encode = [](int x, int y) -> long long {
            return (static_cast<long long>(
                        static_cast<unsigned int>(x)
                    ) << 32)
                    |
                    static_cast<unsigned int>(y);
        };

        unordered_map<long long, int> first;
        first.reserve(2 * n);
        first.max_load_factor(0.7);

        int a = 0, b = 0, c = 0;

        // State before the string starts
        first[encode(0, 0)] = -1;

        for(int i = 0; i < n; i++) {

            if(s[i] == 'a')
                a++;
            else if(s[i] == 'b')
                b++;
            else
                c++;

            int ab = a - b;
            int bc = b - c;

            long long state = encode(ab, bc);

            auto it = first.find(state);

            if(it == first.end()) {
                first[state] = i;
            }
            else {
                maxlen = max(maxlen, i - it->second);
            }
        }

        return maxlen;
    }
};