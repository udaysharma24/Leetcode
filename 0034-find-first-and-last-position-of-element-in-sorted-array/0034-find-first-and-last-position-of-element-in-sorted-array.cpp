class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(binary_search(nums.begin(),nums.end(),target))
        {
            v.push_back(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
            v.push_back(upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1);
        }
        else
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};