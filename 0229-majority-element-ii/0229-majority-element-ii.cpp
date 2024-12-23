class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        set<int> s;
        for(int i=0; i<nums.size(); i++)
        {
            if(m[nums[i]]>nums.size()/3)
                s.insert(nums[i]);
        }
        for(int i:s)
        {
            v.push_back(i);
        }
        return v;
    }
};