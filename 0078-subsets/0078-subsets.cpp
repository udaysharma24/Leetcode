class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back(v);
        // 2 1 0 :: 0/1 0/1 0/1, where 2, 1, 0 are the bits
        int siz= pow(2, nums.size());
        for(int i=0; i<siz; i++)
        {
            vector<int> v;
            for(int j=0; j<nums.size(); j++)
            {
                if(((i>>j)&1))
                    v.push_back(nums[nums.size()-j-1]);
            }
            if(find(ans.begin(), ans.end(), v)==ans.end())
                ans.push_back(v);
        }
        return ans;
    }
};