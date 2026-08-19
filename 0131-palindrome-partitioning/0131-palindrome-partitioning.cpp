class Solution {
public:
    bool palindrome(string cur){
        int l=0;
        int r=cur.length()-1;
        if(cur.length()==0)
            return false;
        bool flag=true;
        while(l<r){
            if(cur[l]==cur[r]){
                l++;
                r--;
            }
            else{
                flag=false;
                break;
            }
        }
        return flag;
    }
    void solve(string cur, string s, int index, vector<string>& news, vector<vector<string>>& ans) {
        if(index == s.length()) {
            ans.push_back(news);
            return;
        }
        for(int end=index; end<s.length(); end++) {
            cur=s.substr(index, end-index+1);
            if(palindrome(cur)) {
                news.push_back(cur);
                solve(cur,s,end+1,news,ans);
                news.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> news;
        int index=0;
        solve("",s,index,news,ans);
        return ans;
    }
};