class Solution {
public:
    void solve(int sindex, int sum, vector<int>& candidates, int target, multiset<int>& s, set<multiset<int>>& ans){
        if(sum>target)
            return;
        else if(sum==target){
            ans.insert(s);
            return;
        }
        else{
            for(int i=sindex; i<candidates.size(); i++){
                if(i > sindex && candidates[i] == candidates[i-1])
                    continue;
                s.insert(candidates[i]);
                solve(i+1,sum+candidates[i],candidates,target,s,ans);
                auto it=s.find(candidates[i]);
                s.erase(it);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        multiset<int> s;
        set<multiset<int>> ans;
        solve(0,0,candidates,target,s,ans);
        auto it=ans.begin();
        vector<vector<int>> finalans;
        while(it!=ans.end()){
            vector<int> v;
            auto it1=(*it).begin();
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