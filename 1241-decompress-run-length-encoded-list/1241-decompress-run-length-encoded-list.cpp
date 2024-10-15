class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        for(int i=1; i<n; i+=2)
        {
            for(int j=0; j<nums[i-1]; j++)
            {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};