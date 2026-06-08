class Solution {
public:
    int minCost(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> m;
        for (int x : A) m[x]++;
        for (int x : B) m[x]--;
        int res = 0;
        for (auto [k, v] : m) {
            if (v % 2) return -1;
            if (v > 0) res += v / 2;
        }
        return res;
    }
};