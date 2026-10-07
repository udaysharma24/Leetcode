class Solution {
public:
    void solve(int index, vector<int>& v, set<vector<int>>& ans, vector<int>& nums){
        if(v.size()>=2)
            ans.insert(v);
        if(index==nums.size())
            return;
        if(v.empty() || nums[index]>=v.back()){
            v.push_back(nums[index]);
            solve(index+1,v,ans,nums);
            v.pop_back();
        }
        solve(index+1,v,ans,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        set<vector<int>> ans;
        solve(0,v,ans,nums);
        vector<vector<int>> finalans;
        auto it=ans.begin();
        while(it!=ans.end()){
            finalans.push_back(*it);
            it++;
        }
        return finalans;
    }
};