class Solution {
public:
    void solve(string temp,
               vector<string>& ans,
               int open,
               int close,
               int n)
    {
        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        if(open < n)
            solve(temp + '(', ans, open + 1, close, n);

        if(close < open)
            solve(temp + ')', ans, open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", ans, 0, 0, n);
        return ans;
    }
};