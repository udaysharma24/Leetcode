class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxval = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        int siz = 0;
        while(maxval > 0) {
            maxval >>= 1;
            siz++;
        }

        vector<int> v(siz, 0);

        int l = 0, r = 0;
        int maxans = 1;

        while(l <= r && r < n) {

            int temp = nums[r];
            int bit = 0;
            bool conflict = false;

            // 1. Check whether nums[r] conflicts
            while(temp > 0) {
                if(temp % 2 == 1 && v[bit] == 1) {
                    conflict = true;
                    break;
                }

                temp >>= 1;
                bit++;
            }

            // 2. Conflict -> remove nums[l]
            if(conflict) {
                temp = nums[l];
                bit = 0;

                while(temp > 0) {
                    if(temp % 2 == 1)
                        v[bit] = 0;

                    temp >>= 1;
                    bit++;
                }

                l++;
            }

            // 3. No conflict -> add nums[r]
            else {
                temp = nums[r];
                bit = 0;

                while(temp > 0) {
                    if(temp % 2 == 1)
                        v[bit] = 1;

                    temp >>= 1;
                    bit++;
                }

                r++;

                maxans = max(maxans, r - l);
            }
        }

        return maxans;
    }
};