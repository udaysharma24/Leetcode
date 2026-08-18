class Solution {
public:
    void solve(int cursum, int curindex, vector<int>& candidates, int target, vector<int> v, vector<vector<int>>& ans){
        if(curindex==candidates.size() || cursum>target)
            return;
        if(cursum==target){
            ans.push_back(v);
            return;
        }
        if(cursum<target){
            v.push_back(candidates[curindex]);
            solve(cursum+candidates[curindex],curindex,candidates,target,v,ans);
            v.pop_back();
        }
        solve(cursum,curindex+1,candidates,target,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,0,candidates,target,v,ans);
        return ans;
    }
};