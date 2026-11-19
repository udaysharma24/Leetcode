class Solution {
public:
    string arrangeWords(string text) {
        string s="";
        vector<pair<string,int>> vps;
        int newidx=0;
        for(int i=0; i<text.length(); i++){
            if(text[i]==' '){
                vps.push_back({s,newidx});
                newidx=i+1;
                s="";
            }
            else
                s.push_back(text[i]);
        }
        if(!s.empty()){
            vps.push_back({s,newidx});
        }
        sort(vps.begin(),vps.end(),[](pair<string,int>& a, pair<string,int>& b){
            if(a.first.length()==b.first.length())
                return a.second<b.second;
            return a.first.length()<b.first.length();
        });
        string ans="";
        for(int i=0; i<vps.size(); i++){
            ans+=vps[i].first;
            ans.push_back(' ');
        }
        if(ans[0]>=97)
            ans[0]=char(ans[0]-32);
        for(int i=1; i<ans.length(); i++){
            if(ans[i]>=65 && ans[i]<=90)
                ans[i]+=32;
        }
        ans.pop_back();
        return ans;
    }
};