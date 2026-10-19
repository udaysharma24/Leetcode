class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(nums);
        int mx=*max_element(nums.begin(),nums.end());
        int bits = 0;
        while (mx > 0) {
            bits++;
            mx >>= 1;
        }
        vector<vector<int>> xormatrix(n, vector<int>(bits));
        for(int i=0; i<n; i++){
            for(int j=bits-1; j>=0; j--){
                xormatrix[i][j]=temp[i]%2;
                temp[i]>>=1;
            }
        }
        int rank = 0;

        for (int j = 0; j < bits && rank < n; j++) {
            int pivot = rank;

            while (pivot < n && xormatrix[pivot][j] == 0) {
                pivot++;
            }

            if (pivot == n) continue;

            swap(xormatrix[rank], xormatrix[pivot]);

            for (int i = rank + 1; i < n; i++) {
                if (xormatrix[i][j] == 1) {
                    for (int k = 0; k < bits; k++) {
                        xormatrix[i][k] ^= xormatrix[rank][k];
                    }
                }
            }

            rank++;
        }
        vector<int> basis;

        for (int i = 0; i < rank; i++) {
            int x = 0;

            for (int j = 0; j < bits; j++) {
                if (xormatrix[i][j] == 1) {
                    x |= (1 << (bits - 1 - j));
                }
            }

            basis.push_back(x);
        }
        int ans = 0;

        for (int x : basis) {
            if ((ans ^ x) > ans) {
                ans ^= x;
            }
        }
        return ans;
    }
};