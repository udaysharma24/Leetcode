class Solution {
public:
    bool ispalindrome(string s){
        int n=s.length();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    void solve(int index, string& s, vector<string>& vs, vector<vector<string>>& ans){
        if(index==s.length()){
            ans.push_back(vs);
            return;
        }
        for(int i=index; i<s.length(); i++){
            string st = s.substr(index, i-index+1);
            if(ispalindrome(st)){
                vs.push_back(st);
                solve(i+1, s, vs, ans);
                vs.pop_back();   
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vs;
        solve(0, s, vs, ans);
        return ans;
    }
};