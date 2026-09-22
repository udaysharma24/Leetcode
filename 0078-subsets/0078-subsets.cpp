class Solution {
public:
    void solve(int curindex, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        if(curindex>=nums.size())
            return;
        v.push_back(nums[curindex]);
        ans.push_back(v);
        solve(curindex+1,nums,v,ans);
        v.pop_back();
        solve(curindex+1,nums,v,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        ans.push_back(v);
        solve(0,nums,v,ans);
        return ans;
    }
};