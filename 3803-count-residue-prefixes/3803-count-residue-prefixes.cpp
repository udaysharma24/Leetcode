class Solution {
public:
    int residuePrefixes(string s) {
        string ans="";
        set<char> st;
        int cnt=0;  
        for(int i=0; i<s.length(); i++){
            ans.push_back(s[i]);
            st.insert(s[i]);
            if(st.size()==(ans.size())%3)
                cnt++;
        }
        return cnt;
    }
};