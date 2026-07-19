class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> visited(26,false);
        string ans="";
        map<char,int> m;
        for(int i=0; i<s.length(); i++){
            m[s[i]]=i;
        }
        for(int i=0; i<s.length(); i++){
            if (visited[s[i]-'a'])
                continue;
            if(!ans.empty()){
                while(ans[ans.length()-1]>s[i] && i<m[ans[ans.length()-1]]){
                    visited[ans[ans.length()-1]-'a']=false;
                    ans.pop_back();
                    if(ans.empty())
                        break;
                }
            }
            if(!visited[s[i]-'a']){
                ans.push_back(s[i]);
                visited[s[i]-'a']=true;
            }
        }
        return ans;
    }
};