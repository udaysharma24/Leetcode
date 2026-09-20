class Solution {
public:
    void solve(int curindex, multiset<int> s, set<multiset<int>>& ans, vector<int>& nums){
        if(curindex>=nums.size())
            return;
        ans.insert(s);
        s.insert(nums[curindex]);
        ans.insert(s);
        solve(curindex+1,s,ans,nums);
        s.erase(nums[curindex]);
        solve(curindex+1,s,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        multiset<int> s;
        set<multiset<int>> ans;
        solve(0,s,ans,nums);
        vector<vector<int>> finalans;
        auto it=ans.begin();
        while(it!=ans.end()){
            auto it1=(*it).begin();
            vector<int> v;
            while(it1!=(*it).end()){
                v.push_back(*it1);
                it1++;
            }
            finalans.push_back(v);
            it++;
        }
        return finalans;
    }
};