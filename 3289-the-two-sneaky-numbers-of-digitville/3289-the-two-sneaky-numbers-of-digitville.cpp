class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> um;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(um.find(nums[i])!=um.end())
                ans.push_back(nums[i]);
            um[nums[i]]++;
        }
        return ans;
    }
};