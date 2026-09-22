class Solution {
public:
    void solve(int curindex, int sum, vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(v);
            return;
        }
        else if(sum>target || curindex>=candidates.size())
            return;
        else{
            v.push_back(candidates[curindex]);
            solve(curindex,sum+candidates[curindex],candidates,target,v,ans);
            v.pop_back();
        }
        solve(curindex+1,sum,candidates,target,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(0,0,candidates,target,v,ans);
        return ans;
    }
};