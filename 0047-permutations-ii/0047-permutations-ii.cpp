class Solution {
public:
    void solve(vector<bool>& visited, vector<int>& nums, vector<int>& v, set<vector<int>>& s){
        if(v.size()==nums.size()){
            s.insert(v);
            for(int i=0; i<v.size(); i++){
                cout<<v[i]<<" ";
            }
            cout<<"\n";
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                v.push_back(nums[i]);
                visited[i]=true;
                solve(visited,nums,v,s);
                visited[i]=false;
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v; 
        set<vector<int>> s;
        vector<bool> visited(nums.size(),false);
        solve(visited,nums,v,s);
        vector<vector<int>> ans;
        auto it=s.begin();
        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};