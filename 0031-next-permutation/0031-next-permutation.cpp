class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(next_permutation(nums.begin(),nums.end()))
        {
            for(int i=0; i<nums.size(); i++)
            {
                cout<<nums[i]<<" ";
            }
        }
        return;
    }
};