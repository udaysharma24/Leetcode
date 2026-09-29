class Solution {
public:
    void solve(vector<int>& nums, vector<int>& v, vector<vector<int>>& ans, vector<bool>& visited){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                v.push_back(nums[i]);
                visited[i]=true;
                solve(nums,v,ans,visited);
                v.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(),false);
        solve(nums,v,ans,visited);
        return ans;
    }
};