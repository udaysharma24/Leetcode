class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target))
            return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        else
            return upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
};