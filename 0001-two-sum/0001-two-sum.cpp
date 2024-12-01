class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                v.push_back(i);
                auto j=m.find((target-nums[i]));
                v.push_back(m[target-nums[i]]);
            }
            else
                m[nums[i]]=i;
        }
        return v;
    }
};