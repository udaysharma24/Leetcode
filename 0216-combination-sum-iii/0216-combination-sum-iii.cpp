class Solution {
public:
    void solve(int start, int sindex, int sum, int& k, int& n, set<int>& s, set<set<int>>& ans){
        if(sindex==k && sum==n){
            auto it=s.begin();
            while(it!=s.end()){
                cout<<*it<<" ";
                it++;
            }
            cout<<"\n";
            ans.insert(s);
            return;
        }
        else if(sindex==k && sum!=n)
            return;
        else if(sum>n)
            return;
        for(int i=start; i<=9; i++){
            if(sum<n){
                s.insert(i);
                solve(i+1,sindex+1,sum+i,k,n,s,ans);
                s.erase(i);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        set<int> s;
        set<set<int>> ans;
        solve(1,0,0,k,n,s,ans);
        vector<vector<int>> finalans;
        auto it1=ans.begin();
        while(it1!=ans.end()){
            vector<int> v;
            auto it2=it1->begin();
            while(it2!=it1->end()){
                v.push_back(*it2);
                it2++;
            }
            finalans.push_back(v);
            it1++;
        }
        return finalans;
    }
};